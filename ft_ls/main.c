/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:30:47 by douglas           #+#    #+#             */
/*   Updated: 2017/09/10 16:07:00 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dir_file(void *item)
{
	free(((t_file*)item)->name);
	free(item);
}

int		main(int argc, char *argv[], char *env[])
{
	t_btree		*dirs;
	char		*options;

	(void)env;
	options = get_options(argc, argv);
	dirs = NULL;
	get_args(argc, argv, options, &dirs);
	btree_apply_infix(dirs, get_files);
	btree_free(&dirs, free_dir_file);
	free(options);
	return (0);
}
