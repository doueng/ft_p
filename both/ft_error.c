/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:20 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void	ft_errormsg(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(-1);
}

void	ft_error(char *file, int line)
{
	ft_printf("Error:\n\tFile: %s\n\tLine: %d", file, line);
	exit(-1);
}
