/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:27 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*cmd_pwd(t_env *env)
{
	int		i;
	char	*cwd;
	char	*res;

	i = 0;
	cwd = Xv(getcwd(NULL, 0));
	if (ft_strequ(env->root, cwd))
		res = ft_strdup("root");
	else
	{
		while (env->root[i] == cwd[i])
			i++;
		res = Xv(ft_strdup(cwd + i));
	}
	free(cwd);
	return (res);
}
