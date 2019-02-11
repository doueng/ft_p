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

static int	print_file_line(char *file, int line)
{
	char *strline;

	if (!(strline = ft_itoa(line)))
	{
		ft_putendl_fd("itoa failed in print_errmsg", 2);
		return (-1);
	}
	ft_putendl_fd("fild: ", 2);
	ft_putendl_fd(file, 2);
	ft_putendl_fd(strline, 2);
	return (-1);
}

int			x_int(int res, char *file, int line)
{
	if (res == -1)
		exit(print_file_line(file, line));
	return (res);
}

void		*x_void(void *res, char *file, int line)
{
	if (res == NULL)
		exit(print_file_line(file, line));
	return (res);
}
