/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:57 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		sender(int sockfd, t_env *env)
{
	if (env->cmd == -1)
	{
		ft_putstr_fd("Invalid command\n", 2);
		return (-1);
	}
	if (env->cmd == PUT)
		return (send_file(sockfd, env));
	else if (env->cmd == GET)
		return (get_file(sockfd, env));
	return (send_cmd(sockfd, env));
}

static void		prompt(void)
{
	ft_putstr(BOLD_TEXT);
	ft_print_color("client", CYAN_COLOR);
	ft_putstr(" 👉  ");
	ft_putstr(NORMAL_COLOR);
}

static char		*get_line(int fd)
{
	char	*line;
	char	buff[2];
	char	*rev_line;

	line = ft_strnew(1);
	ft_bzero(&buff, 2);
	while (X(read(fd, &buff, 1)))
	{
		if (*buff == '\n')
			break;
		line = Xv(ft_strjoinfree(0, buff, 1, line));
	}
	rev_line = Xv(ft_strrev(line));
	return (rev_line);
}

static char	get_cmd_code(char *line)
{
	char	cmd_code;
	char	*cmd_end;

	cmd_code = -1;
	if ((cmd_end = ft_strchr(line, ' ')))
		*cmd_end = 0;
	cmd_code = (ft_strequ("cd", line)) ? CD : cmd_code;
	cmd_code = (ft_strequ("ls", line)) ? LS : cmd_code;
	cmd_code = (ft_strequ("pwd", line)) ? PWD : cmd_code;
	cmd_code = (ft_strequ("get", line)) ? GET : cmd_code;
	cmd_code = (ft_strequ("put", line)) ? PUT : cmd_code;
	cmd_code = (ft_strequ("mkdir", line)) ? MKDIR : cmd_code;
	cmd_code = (ft_strequ("rmdir", line)) ? RMDIR : cmd_code;
	cmd_code = (ft_strequ("quit", line)) ? QUIT : cmd_code;
	cmd_code = (ft_strequ("help", line)) ? HELP : cmd_code;
	return (cmd_code);
}

static void		get_env(t_env *env, char *line)
{
	char *tline;

	ft_bzero(env, sizeof(*env));
	tline = Xv(ft_strtrim(line));
	free(line);
	if ((env->args = ft_strchr(tline, ' ')))
		env->args = ft_strtrim(env->args);
	env->cmd = get_cmd_code(tline);
	env->line = tline;
}

void			main_loop(int sockfd)
{
	char	*line;
	t_env	env;

	prompt();
	while ((line = get_line(STDIN_FILENO)))
	{
		get_env(&env, line);
		if (0 == sender(sockfd, &env))
			print_response(sockfd);
		if (env.args)
			free(env.args);
		free(env.line);
		if (env.cmd == QUIT)
			break ;
		prompt();
	}
}
