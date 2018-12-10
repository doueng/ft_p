#include "server.h"

char	*process_cmd(char *cmd, int cfd)
{
	char *res;

	if (ft_strequ(cmd, "ls"))
		res = cmd_ls(cfd);
	else if (ft_strequ(cmd, "get"))
		res = cmd_get(cfd);
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
	char		cmd[5];
	char		*cmd_ret;
	uint32_t	len;

	while (1)
	{
		X(read(cfd, cmd, 5));
		ft_printf("cmd ((%s))\n", cmd);
		if (ft_strequ(cmd, "quit"))
			break ;
		cmd_ret = process_cmd(cmd, cfd);
		len = ft_strlen(cmd_ret);
		send(cfd, &len, 4, 0);
		write(cfd, cmd_ret, len);
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

int		start_listening(int port)
{
	struct sockaddr_in	servaddr;
	int					lfd;

	X((lfd = get_socket()));
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	X(bind(lfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
	X(listen(lfd, 42));
	return (lfd);
}

int main(int argc, char *argv[])
{
	int					lfd;
	int					cfd;

	if (argc != 2)
		return (ft_putstr("Usage: ./server <PORT>\n"));
	X(chdir("./data"));
	lfd = start_listening(ft_atoi(argv[1]));
	while (1)
	{
		X((cfd = accept(lfd, (struct sockaddr*)NULL, NULL)));
		X(forker(cfd));
	}
	close(lfd);
	return (0);
}
