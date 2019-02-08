/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:20 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*file_to_str(char *path)
{
	struct stat st;
	char		*str;
	int			fd;

	fd = X(open(path, O_RDONLY));
	X(fstat(fd, &st));
	Xv((str = ft_strnew(st.st_size)));
	X(read(fd, str, st.st_size - 1));
	X(close(fd));
	return (str);
}

char		*cmd_ls(t_env *env)
{
	pid_t	pid;
	int		fd;
	char	*arg;
	char	*full_arg;

	arg = env->arg;
	if (arg != NULL && -1 == check_path(env->server_data_path, arg))
		return (ft_strdup("Invalid argument"));
	full_arg = Xv(ft_strjoin("ft_ls ", arg ? arg : ""));
	X((pid = fork()));
	if (pid == 0)
	{
		X(fd = open(env->tmp_path, O_CREAT | O_RDWR | O_TRUNC | O_SHLOCK));
		X(dup2(fd, STDOUT_FILENO));
		X(close(fd));
		exit(execv(env->ls_path, ft_strsplit(full_arg, ' ')));
	}
	else
	{
		wait(&pid);
		free(full_arg);
	}
	return (file_to_str(env->tmp_path));
}
