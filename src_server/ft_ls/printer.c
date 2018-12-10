/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 02:21:06 by douglas           #+#    #+#             */
/*   Updated: 2017/09/11 14:31:20 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				is_executable(int mode)
{
	return (S_ISREG(mode)
			&& (mode & S_IXUSR
			|| mode & S_IXGRP
			|| mode & S_IXOTH));
}

void			print_name(void *file)
{
	char			*name;
	int				mode;
	char			*options;

	mode = ((t_file*)file)->lstat.st_mode;
	name = ((t_file*)file)->name;
	options = ((t_file*)file)->options;
	if (options[e_a] != 'a' && name[0] == '.')
		return ;
	(options[e_l]) ? ft_putchar(' ') : 0;
	if (S_ISDIR(mode) && options[e_G])
		ft_print_color(name, CYAN_COLOR);
	else if (S_ISLNK(mode) && options[e_G])
		ft_print_color(name, MAGENTA_COLOR);
	else if (is_executable(mode) && options[e_G])
		ft_print_color(name, RED_COLOR);
	else
		ft_putstr(name);
	(options[e_p] && S_ISDIR(mode)) ? ft_putchar('/') : 0;
	(options[e_1] == '1'
		&& options[e_l] != 'l'
		&& options[e_g] != 'g') ? ft_putchar('\n') : 0;
}

static size_t	print_total(t_btree *node)
{
	if (!node)
		return (0);
	return (print_total(node->left)
			+ print_total(node->right)
			+ ((t_file*)node->item)->lstat.st_blocks);
}

void			printer(t_btree *root, char *options, char *path)
{
	static int first = 1;

	if (!root)
		return ;
	if (path && (!first || options[e_ac] > 1))
		ft_printf("%s:\n", path);
	if (options[e_l] && !((t_file*)root->item)->empty)
		ft_printf("total %zu\n", print_total(root));
	first = 0;
	if (options[e_l])
		btree_apply_infix(root, print_l);
	else if (options[e_1] == '1')
		btree_apply_infix(root, print_name);
	else
		print_pages(root);
	if (options[e_R])
		ft_printf("\n");
}
