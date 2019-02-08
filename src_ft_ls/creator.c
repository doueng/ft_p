/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:03:37 by douglas           #+#    #+#             */
/*   Updated: 2017/09/07 17:58:09 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*path_maker(char *path, char *file)
{
	char *new_path;

	if (!(new_path = ft_strjoinfree(0, path, 0, "/")))
		ft_error("Malloc failed");
	if (!(new_path = ft_strjoinfree(1, new_path, 0, file)))
		ft_error("Malloc failed");
	return (new_path);
}

static int		get_last_slash(char *path)
{
	int i;
	int slash;

	i = 0;
	slash = 0;
	while (path[i])
	{
		(path[i] == '/') ? slash = i : 0;
		i++;
	}
	return (slash);
}

static char		*get_name(char *path)
{
	char	*name;
	int		slash;

	slash = get_last_slash(path);
	if (!(name = ft_strdup(&path[(slash) ? slash + 1 : 0])))
		ft_error("Malloc failed");
	return (name);
}

t_file			*file_maker(char *options, char *path)
{
	t_file			*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		ft_error("Malloc failed");
	file->options = options;
	stat(path, &(file->stat));
	lstat(path, &(file->lstat));
	file->xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	file->path = path;
	file->name = get_name(path);
	file->empty = 0;
	return (file);
}

t_nth			*nth_maker(int num)
{
	t_nth *nth;

	if (!(nth = (t_nth*)malloc(sizeof(t_nth))))
		ft_error("Mallor failed");
	nth->nth = num;
	return (nth);
}
