#include "server.h"

char	*cmd_put(int cfd)
{
	char	*file_name;
	off_t	file_size;
	int		filefd;
	char	buff;

	file_name = NULL;
	X(get_next_line(cfd, &file_name));
	X(read(cfd, &file_size, sizeof(off_t)));
	ft_printf("filesize: (%d)\n", file_size);
	file_name += 3;
	while (*file_name == ' ')
		file_name++;
	X((filefd = open(file_name, O_WRONLY | O_CREAT | O_APPEND)));
	while (file_size--)
	{
		X(read(cfd, &buff, 1));
		X(write(filefd, &buff, 1));
	}
	return (Xv(ft_strdup("File uploaded!!!!")));
}

char	*process_cmd(char *cmd, int cfd)
{
	char *res;

	res = "Invalid command";
	if (ft_strequ(cmd, "ls"))
		res = cmd_ls();
	else if (ft_strequ(cmd, "put"))
		res = cmd_put(cfd);
	else if (ft_strequ(cmd, "pwd"))
		res = cmd_pwd();
	else
		Xv((res = ft_strdup("Invalid command")));
	return (res);
}

int read_cmd(int cfd)
{
	char		*cmd;
	char		*cmd_ret;
	uint32_t	len;

	while (1)
	{
		cmd = NULL;
		X(get_next_line(cfd, &cmd));
		cmd_ret = process_cmd(cmd, cfd);
		len = ft_strlen(cmd_ret);
		send(cfd, &len, 4, 0);
		write(cfd, cmd_ret, len);
		free(cmd);
		free(cmd_ret);
	}
	return (0);
}

int forker(int cfd)
{
	pid_t		pid;
	/* int			stat_loc; */

	X((pid = fork()));
	if (pid == 0)
		read_cmd(cfd);
	/* else */
		/* X(wait4(pid, &stat_loc, 0, 0)); */
	return (1); // needs error handling
	/* return (WEXITSTATUS(stat_loc)); */
}

int main(void)
{
	int					lfd;
	int					cfd;
	struct sockaddr_in	servaddr;

	X(chdir("./data"));
	X((lfd = get_socket()));
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	X(bind(lfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
	X(listen(lfd, 42));
	while (1)
	{
		X((cfd = accept(lfd, (struct sockaddr*)NULL, NULL)));
		X(forker(cfd));
	}
	return (0);
}
