#include "server.h"

char	*process_cmd(char *cmd, int cfd, t_env *env)
{
	char *res;
	char *arg;

	arg = get_msg(cfd);
	if (ft_strequ(cmd, "ls"))
		res = cmd_ls(arg, env);
	else if (ft_strequ(cmd, "get"))
		res = cmd_get(cfd, arg);
	else if (ft_strequ(cmd, "put"))
		res = cmd_put(cfd, arg);
	else if (ft_strequ(cmd, "pwd"))
		res = cmd_pwd();
	else if (ft_strequ(cmd, "cd"))
		res = cmd_cd(arg);
	else
		Xv((res = ft_strdup("Invalid command")));
	return (res);
}

int read_cmd(int cfd, t_env *env)
{
	char		cmd[5];
	char		*cmd_ret;

	while (1)
	{
		X(read(cfd, cmd, 5));
		if (ft_strequ(cmd, "quit"))
			break ;
		cmd_ret = process_cmd(cmd, cfd, env);
		send_msg(cfd, cmd_ret);
		free(cmd_ret);
	}
	send_msg(cfd, "Connection terminated");
	X(close(cfd));
	return (0);
}

int forker(int cfd, t_env *env)
{
	pid_t		pid;
	/* int			stat_loc; */

	X((pid = fork()));
	if (pid == 0)
		exit(read_cmd(cfd, env));
	/* else */
		/* X(wait4(pid, &stat_loc, 0, 0)); */
	return (1); // needs error handling
	/* return (WEXITSTATUS(stat_loc)); */
}

t_env		*create_env(void)
{
	t_env	*env;
	char	*cwd;

	Xv((env = (t_env*)malloc(sizeof(t_env))));
	Xv((cwd = getcwd(NULL, 0)));
	env->ls_path = Xv(ft_strjoin(cwd, "/bin/ft_ls"));
	env->tmp_path = Xv(ft_strjoin(cwd, "/tmp/tmp"));
	free(cwd);
	return (env);
}

int main(int argc, char *argv[])
{
	int		lfd;
	int		cfd;
	t_env	*env;

	if (argc != 2)
		return (ft_putstr("Usage: ./server <PORT>\n"));
	Xv((env = create_env()));
	X(chdir("./data"));
	lfd = start_listening(ft_atoi(argv[1]));
	while (1)
	{
		X((cfd = accept(lfd, (struct sockaddr*)NULL, NULL)));
		X(forker(cfd, env));
	}
	close(lfd);
	return (0);
}
