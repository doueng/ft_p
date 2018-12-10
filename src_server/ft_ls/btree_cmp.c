/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 19:58:40 by douglas           #+#    #+#             */
/*   Updated: 2017/09/11 14:51:05 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_ascii(void *a, void *b)
{
	char	*name_a;
	char	*name_b;
	int		rev;

	name_a = ((t_file*)a)->name;
	name_b = ((t_file*)b)->name;
	rev = (((t_file*)a)->options[e_r]) ? 1 : -1;
	return (ft_strcmp(name_a, name_b) * rev);
}

int			cmp_time(void *a, void *b)
{
	int time_mod_a;
	int time_mod_b;
	int rev;

	time_mod_a = ((t_file*)a)->lstat.st_mtime;
	time_mod_b = ((t_file*)b)->lstat.st_mtime;
	if (time_mod_a == time_mod_b)
		return (cmp_ascii(a, b));
	rev = (((t_file*)a)->options[e_r]) ? 1 : -1;
	return ((time_mod_b - time_mod_a) * rev);
}

int			cmp_unorderd(void *a, void *b)
{
	(void)a;
	(void)b;
	return (1);
}

int			cmp_params(void *a, void *b)
{
	char	*options;

	(void)a;
	(void)b;
	options = ((t_file*)a)->options;
	if (options[e_r])
		return (-1);
	return (1);
}

int			cmp_size(void *a, void *b)
{
	int size_a;
	int size_b;
	int rev;

	size_a = ((t_file*)a)->lstat.st_size;
	size_b = ((t_file*)b)->lstat.st_size;
	if (size_a == size_b)
		return (cmp_ascii(a, b));
	rev = (((t_file*)a)->options[e_r]) ? 1 : -1;
	return ((size_b - size_a) * rev);
}
