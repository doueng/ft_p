#include "client.h"

void	connect_to_srv(int sockfd, char *address)
{
	struct sockaddr_in	servaddr;

	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	X(inet_pton(AF_INET, address, &servaddr.sin_addr)); // check zero, non parsable, man 3 inet
	X(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
}

void	print_answer(int sockfd)
{
	char	*answer;
	int		len;

	read(sockfd, &len, 4);
	Xv(answer = ft_strnew(len));
	read(sockfd, answer, len);
	ft_printf("%s\n", answer);
	free(answer);
}

void	send_cmd(int sockfd, char *cmd)
{
	uint32_t len;

	len = ft_strlen(cmd);
	cmd[len] = '\n';
	write(sockfd, cmd, len + 1);
}

void	send_file(int sockfd, char *cmd)
{
	struct stat st;
	int			fd;
	void		*file;
	int			len;

	write(sockfd, "put\n", 4);
	X((fd = open(cmd + 4, O_RDONLY)));
	X(fstat(fd, &st));
	Xv((file = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)));
	len = ft_strlen(cmd);
	cmd[len] = '\n';
	X(write(sockfd, cmd, len + 1));
	X(write(sockfd, &st.st_size, sizeof(off_t)));
	X(write(sockfd, (char*)file, st.st_size));
	X(munmap(file, st.st_size));
	close(fd);
}

void	sender(int sockfd, char *cmd)
{
	if (0 == ft_strncmp(cmd, "put", 3))
		send_file(sockfd, cmd);
	else
		send_cmd(sockfd, cmd);
}

void	prompt(void)
{
	ft_printf("Server :::  ");
}

void	main_loop(int sockfd)
{
	char	*cmd;
	int		ret;

	cmd = NULL;
	prompt();
	while ((ret = get_next_line(0, &cmd)))
	{
		X(ret);
		sender(sockfd, cmd);
		print_answer(sockfd);
		free(cmd);
		cmd = NULL;
		prompt();
	}
}

int main(int argc, char *argv[])
{
	int					sockfd;

	if (argc != 2)
		return (ft_printf("wrong number args\n"));
	sockfd = get_socket();
	connect_to_srv(sockfd, argv[1]);
	main_loop(sockfd);
	return (0);
}
