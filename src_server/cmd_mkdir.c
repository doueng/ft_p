/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mkdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:22 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*cmd_mkdir(t_env *env)
{
	char *res;
	char *new_dir_path;

	if (env->arg == NULL && -1 == check_path(env->root, env->arg))
		return (ft_strdup("Invalid argument"));
	new_dir_path = add_to_cwd(env->arg);
	res = (mkdir(new_dir_path, 0755)) == -1
		? "Failed to create "
		: "Created ";
	free(new_dir_path);
	return (XV(ft_strjoin(res, env->arg)));
}
