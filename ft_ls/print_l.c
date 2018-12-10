/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:22:33 by douglas           #+#    #+#             */
/*   Updated: 2017/09/11 14:30:27 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_permissons(int mode)
{
	char perms[11];

	perms[0] = (S_ISDIR(mode)) ? 'd' : '-';
	(S_ISLNK(mode)) ? perms[0] = 'l' : 0;
	perms[1] = (mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (mode & S_IXUSR) ? 'x' : '-';
	if (mode & S_ISUID)
		perms[3] = (perms[3] == 'x') ? 's' : 'S';
	perms[4] = (mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (mode & S_IXGRP) ? 'x' : '-';
	if (mode & S_ISGID)
		perms[6] = (perms[6] == 'x') ? 's' : 'S';
	perms[7] = (mode & S_IROTH) ? 'r' : '-';
	perms[8] = (mode & S_IWOTH) ? 'w' : '-';
	perms[9] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		perms[9] = (perms[9] == 'x') ? 't' : 'T';
	perms[10] = '\0';
	ft_putstr(perms);
}

static void		print_name_l(t_file *file)
{
	char	*buffer;
	int		size;

	size = file->lstat.st_size;
	if (!(buffer = ft_strnew(size)))
		ft_error("Malloc failed");
	print_name(file);
	if (S_ISLNK(file->lstat.st_mode))
	{
		if (0 > readlink(file->path, buffer, size))
			perror(strerror(errno));
		ft_printf(" -> %s", buffer);
	}
	free(buffer);
	ft_putchar('\n');
}

static void		print_time(struct stat stat)
{
	char		*date;
	long long	time_diff;
	int			i;

	if (!(date = ctime(&stat.st_mtime)))
		ft_error("ctime returned an error");
	ft_print_till(&date[4], ' ');
	ft_putchar(' ');
	i = (date[8] == ' ') ? ft_putchar(' ') + 8 : 8;
	ft_print_till(&date[i], ' ');
	ft_putchar(' ');
	time_diff = stat.st_mtime - time(NULL);
	time_diff *= (time_diff < 0) ? -1 : 1;
	if (time_diff < 15552000)
	{
		ft_print_till(&date[11], ':');
		ft_putchar(':');
		ft_print_till(&date[14], ':');
	}
	else
	{
		ft_putchar(' ');
		ft_print_till(&date[20], '\n');
	}
}

static int		get_pw_name(char **pw_name, int st_uid, t_file *file)
{
	struct passwd	*pass;
	int				malloced;

	malloced = 0;
	pass = NULL;
	if (file->options[e_g] == 'g')
		*pw_name = "";
	else if (!(pass = getpwuid(st_uid)))
	{
		*pw_name = num_to_string(st_uid);
		malloced = 1;
	}
	else
		*pw_name = pass->pw_name;
	return (malloced);
}

void			print_l(void *tree_file)
{
	t_file			*file;
	struct stat		lstat;
	struct group	*grp;
	int				malloced;
	char			*pw_name;

	file = (t_file*)tree_file;
	if (file->name[0] == '.' && file->options[e_a] != 'a')
		return ;
	lstat = file->lstat;
	print_permissons(lstat.st_mode);
	print_extra(file);
	grp = getgrgid(lstat.st_gid);
	malloced = get_pw_name(&pw_name, lstat.st_uid, file);
	ft_printf("%3d %s %s %6zu ",
				lstat.st_nlink,
				pw_name,
				(grp) ? grp->gr_name : "",
				lstat.st_size);
	print_time(lstat);
	print_name_l(file);
	if (malloced)
		free(pw_name);
}
