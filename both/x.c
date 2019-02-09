/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:36 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	print_errmsg(char *file, int line)
{
	char *strline;

	if (!(strline = ft_itoa(line)))
	{
		ft_putendl_fd("itoa failed in print_errmsg", 2);
		exit(-1);
	}
	ft_putendl_fd("fild: ", 2);
	ft_putendl_fd(file, 2);
	ft_putendl_fd(strline, 2);
	exit(-1);
}

int		x_int(int res, char *file, int line)
{
	if (res == -1)
		print_errmsg(file, line);
	return (res);
}

void	*x_void(void *res, char *file, int line)
{
	if (res == NULL)
		print_errmsg(file, line);
	return (res);
}
