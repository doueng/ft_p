/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rmdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:33 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <errno.h> // remove
#include <stdio.h> // remove

char		*cmd_rmdir(t_env *env)
{
	char *res;
	char *dir_path;

	if (env->arg == NULL && -1 == check_path(env->server_data_path, env->arg))
		return (ft_strdup("Invalid argument"));
	dir_path = add_to_cwd(env->arg);
	res = (unlink(dir_path)) == -1 ? "Failed to remove " : "Removed dir ";
	free(dir_path);
	perror(strerror(errno)); // remove
	return (Xv(ft_strjoin(res, env->arg)));
}
