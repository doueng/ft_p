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

char		*cmd_rmdir(t_env *env)
{
	char *res;
	char *dir_path;

	if (env->arg == NULL && -1 == check_path(env->root, env->arg))
		return (ft_strdup("Invalid argument"));
	if (ft_strequ(".", env->arg) || ft_strequ("..", env->arg))
		return (ft_strdup("Can't delete '.' or '..'"));
	dir_path = add_to_cwd(env->arg);
	res = (rmdir(dir_path)) == -1 ? "Failed to remove " : "Removed dir ";
	free(dir_path);
	return (XV(ft_strjoin(res, env->arg)));
}
