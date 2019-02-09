/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:20:30 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/08 20:20:31 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

void		get_env(t_env *env, char *line)
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

int			get_file(int sockfd, t_env *env)
{
	uint64_t	filesize;
	char		*res;

	send_cmd(sockfd, env);
	X(read(sockfd, &filesize, NUM_BYTES_FILESIZE));
	if (filesize > 0)
		write_to_file(sockfd, env->args, filesize);
	res = get_msg(sockfd);
	ft_putstr(res);
	return (0);
}

char		*get_line(int fd)
{
	char	*line;
	char	buff[2];
	char	*rev_line;

	line = ft_strnew(1);
	ft_bzero(&buff, 2);
	while (X(read(fd, &buff, 1)))
	{
		if (*buff == '\n')
			break ;
		line = Xv(ft_strjoinfree(0, buff, 1, line));
	}
	rev_line = Xv(ft_strrev(line));
	return (rev_line);
}
