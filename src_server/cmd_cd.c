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
		return (ft_strdup("Usage: cd folder"));
	if (-1 == check_path(env->server_data_path, new_path))
		return (Xv(ft_strdup("Cannot move outside the data directory")));
	if (-1 == chdir(new_path))
		return (Xv(ft_strdup("Not a valid directory")));
	return (Xv(getcwd(NULL, 0)));
}
