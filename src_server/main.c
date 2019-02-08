/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:36 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			read_cmd(t_env *env, char *(**cmd_funcs)(t_env *env))
{
	uint8_t		cmd;
	char		*cmd_ret;

	while (1)
	{
		X(read(env->cfd, &cmd, 1));
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

int			forker(t_env *env, char *(**cmd_funcs)(t_env *env))
{
	/* int			stat_loc; */
	pid_t		pid;

	X((pid = fork()));
	if (pid == 0)
		exit(read_cmd(env, cmd_funcs));
	/* else */
		/* X(wait4(pid, &stat_loc, 0, 0)); */
	return (1); // needs error handling
	/* return (WEXITSTATUS(stat_loc)); */
}

t_env		*create_env(t_env *env)
{
	char	*cwd;

	Xv((cwd = getcwd(NULL, 0)));
	env->ls_path = Xv(ft_strjoin(cwd, "/ft_ls"));
	env->tmp_path = Xv(ft_strjoin(cwd, "/tmp/tmp"));
	env->server_data_path = ft_strjoin(cwd, "/server_data");
	free(cwd);
	return (env);
}

void		*get_cmd_funcs(void)
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
	cmd_funcs[HELP] = cmd_help;
	return (cmd_funcs);
}

int			main(int argc, char *argv[])
{
	int		lfd;
	t_env	env;
	void	*cmd_funcs;

	if (argc != 2)
		return (ft_putstr("Usage: ./server <PORT>\n"));
	create_env(&env);
	cmd_funcs = get_cmd_funcs();
	X(chdir("server_data"));
	lfd = start_listening(ft_atoi(argv[1]));
	while (1)
	{
		X((env.cfd = accept(lfd, (struct sockaddr*)NULL, NULL)));
		ft_printf("Socket %d connected\n", env.cfd);
		X(forker(&env, cmd_funcs));
	}
	free(env.ls_path);
	free(env.tmp_path);
	free(env.server_data_path);
	close(lfd);
	return (0);
}
