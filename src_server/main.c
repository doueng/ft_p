#include "server.h"

int read_cmd(t_env *env, char *(**cmd_funcs)(t_env *env))
{
	uint8_t		cmd;
	char		*cmd_ret;

	while (1)
	{
		X(read(env->cfd, &cmd, 1));
		ft_printf("cmd %d, quit %d\n", cmd, QUIT);
		env->arg = get_msg(env->cfd);
		cmd_ret = cmd_funcs[cmd](env);
		send_msg(env->cfd, cmd_ret);
		free(cmd_ret);
		if (cmd == QUIT)
			break ;
	}
	X(close(env->cfd));
	return (0);
}

int forker(t_env *env, char *(**cmd_funcs)(t_env *env))
{
	pid_t		pid;
	/* int			stat_loc; */

	X((pid = fork()));
	if (pid == 0)
		exit(read_cmd(env, cmd_funcs));
	/* else */
		/* X(wait4(pid, &stat_loc, 0, 0)); */
	return (1); // needs error handling
	/* return (WEXITSTATUS(stat_loc)); */
}

t_env		*create_env(void)
{
	t_env	*env;
	char	*cwd;

	Xv((env = (t_env*)ft_memalloc(sizeof(t_env))));
	Xv((cwd = getcwd(NULL, 0)));
	env->ls_path = Xv(ft_strjoin(cwd, "/bin/ft_ls"));
	env->tmp_path = Xv(ft_strjoin(cwd, "/tmp/tmp"));
	free(cwd);
	return (env);
}

void	*get_cmd_funcs(void)
{
	char *(**cmd_funcs)(t_env *env);

	cmd_funcs = Xv(malloc(sizeof(void*) * NUM_CMDS));
	cmd_funcs[CD] = cmd_cd;
	cmd_funcs[LS] = cmd_ls;
	cmd_funcs[PWD] = cmd_pwd;
	cmd_funcs[GET] = cmd_get;
	cmd_funcs[PUT] = cmd_put;
	cmd_funcs[MKDIR] = cmd_mkdir;
	cmd_funcs[RMDIR] = cmd_rmdir;
	cmd_funcs[QUIT] = cmd_quit;
	return (cmd_funcs);
}

int main(int argc, char *argv[])
{
	int		lfd;
	t_env	*env;
	void	*cmd_funcs;

	if (argc != 2)
		return (ft_putstr("Usage: ./server <PORT>\n"));
	Xv((env = create_env()));
	cmd_funcs = get_cmd_funcs();
	X(chdir("./data"));
	lfd = start_listening(ft_atoi(argv[1]));
	while (1)
	{
		X((env->cfd = accept(lfd, (struct sockaddr*)NULL, NULL)));
		ft_printf("Socket %d connected\n", env->cfd);
		X(forker(Xv(ft_memdup(env, sizeof(*env))), cmd_funcs));
	}
	free(env->ls_path);
	free(env->tmp_path);
	free(env);
	close(lfd);
	return (0);
}
