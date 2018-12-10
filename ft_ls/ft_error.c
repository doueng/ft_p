/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:08:59 by dengstra          #+#    #+#             */
/*   Updated: 2017/09/11 16:09:01 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(char *message)
{
	ft_putstr(RED_COLOR);
	ft_printf("Error: %s\n", message);
	ft_putstr(NORMAL_COLOR);
	exit(-1);
}

void		ft_usage(char option)
{
	ft_printf("ft_ls: illegal option -- %c\n", option);
	ft_putstr("usage: ./ft_ls [-lRartG1gpSf] [file ...]\n");
	exit(-1);
}

void		permission_denied(char *options, char *path)
{
	int		i;
	char	*c;

	i = 0;
	c = path;
	(options[e_R]) ? ft_printf("%s:\n", path) : 0;
	while (path[i])
		if (path[i++] == '/')
			c = &(path[i]);
	ft_printf("ft_ls: %s: Permission denied\n", c);
	(options[e_R]) ? ft_putstr("\n") : 0;
}
