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

void	prompt(void)
{
	ft_printf("Server :::  ");
}

void	send_cmd(int sockfd)
{
	char	*cmd;
	int		ret;

	cmd = NULL;
	prompt();
	while ((ret = get_next_line(0, &cmd)))
	{
		X(ret);
		cmd[ft_strlen(cmd)] = '\n';
		write(sockfd, cmd, ft_strlen(cmd));
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
	send_cmd(sockfd);
	return (0);
}
