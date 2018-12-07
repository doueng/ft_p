#include "server.h"

char	*process_cmd(char *cmd)
{
	char *res;

	res = "Invalid command";
	if (ft_strequ(cmd, "ls"))
		res = cmd_ls();
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
		cmd_ret = process_cmd(cmd);
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
