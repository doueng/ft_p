/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 01:41:35 by douglas           #+#    #+#             */
/*   Updated: 2017/09/11 15:19:39 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		insert_files(t_btree **files, DIR *directory, char *options,
								char *path)
{
	struct dirent	*file_info;
	char			*name;
	t_file			*file;
	int				count;

	count = 0;
	while ((file_info = readdir(directory)))
	{
		name = file_info->d_name;
		if (options[e_a] != 'a' && name[0] == '.')
			continue;
		count++;
		file = file_maker(options, path_maker(path, name));
		insert_in_tree(files, file, options);
	}
	if (count == 0)
	{
		file = file_maker(options, path_maker(path, name));
		file->empty = 1;
		insert_in_tree(files, file, options);
	}
}

void			get_dirs(void *item)
{
	char			*name;
	int				mode;

	mode = ((t_file*)item)->lstat.st_mode;
	name = ((t_file*)item)->name;
	if (ft_strcmp(name, ".")
			&& ft_strcmp(name, "..")
			&& S_ISDIR(mode))
	{
		get_files(item);
	}
}

void			get_files(void *item)
{
	DIR				*directory;
	t_btree			*files;
	char			*options;
	char			*path;

	options = ((t_file*)item)->options;
	path = ((t_file*)item)->path;
	files = NULL;
	if (!(directory = opendir(path)))
		return (permission_denied(options, path));
	insert_files(&files, directory, options, path);
	printer(files, options, path);
	if (options[e_R] == 'R')
		btree_apply_infix(files, get_dirs);
	btree_free(&files, free_item);
	closedir(directory);
}
