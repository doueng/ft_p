/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:14 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*cmd_cd(t_env *env)
{
	char	*new_path;

	if (!(new_path = env->arg))
		return ((XV(ft_strdup("Usage: cd folder"))));
	if (-1 == check_path(env->root, new_path))
		return (XV(ft_strdup("Invalid path")));
	if (-1 == chdir(new_path))
		return (XV(ft_strdup("Not a valid directory")));
	return (ft_strdup(env->arg));
}
