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
#include <stdio.h>
#include <errno.h>

int		x_int(int res, char *file, int line)
{
	if (res == -1)
	{
		ft_printf("file: %s\nline: %d\n", file, line);
		perror(strerror(errno));
		exit(1);
	}
	return (res);
}

void	*x_void(void *res, char *file, int line)
{
	if (res == NULL)
	{
		ft_printf("file: %s\nline: %d\n", file, line);
		perror(strerror(errno));
		exit(1);
	}
	return (res);
}
