/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directories.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:50:01 by douglas           #+#    #+#             */
/*   Updated: 2017/09/10 16:05:28 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_arg(char *arg, char *options, t_btree **dirs, t_btree **files)
{
	struct stat	lstats;
	struct stat	stats;
	t_file		*file;

	if (lstat(arg, &lstats) < 0 || stat(arg, &stats) < 0)
		return ((void)ft_printf("ft_ls: %s: No such file or directory\n", arg));
	file = file_maker(options, arg);
	free(file->name);
	file->name = ft_strdup(file->path);
	if (S_IFLNK & lstats.st_mode && options[e_l] != 'l'
				&& S_IFDIR & stats.st_mode)
		insert_in_tree(dirs, file, options);
	else if (S_ISDIR(lstats.st_mode))
		insert_in_tree(dirs, file, options);
	else
	{
		file->empty = 1;
		if (options[e_l] != 'l')
			file->stat = stats;
		insert_in_tree(files, file, options);
	}
}

void	get_args(int ac, char *av[], char *options, t_btree **dirs)
{
	t_btree		*files;
	int			dir_arg;
	int			i;

	files = NULL;
	dir_arg = 0;
	i = 1;
	while (--ac)
	{
		if (ft_strequ(av[i], "-") || av[i][0] != '-')
		{
			insert_arg(av[i], options, dirs, &files);
			dir_arg = 1;
		}
		i++;
	}
	if (dir_arg == 0)
		insert_in_tree(dirs, file_maker(options, "."), options);
	if (files)
	{
		printer(files, options, NULL);
		btree_free(&files, free_item_name);
		if (*dirs)
			ft_putchar('\n');
	}
}
