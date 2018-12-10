/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:31:14 by douglas           #+#    #+#             */
/*   Updated: 2017/09/10 16:27:47 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

enum
{
	e_l,
	e_R,
	e_a,
	e_r,
	e_t,
	e_G,
	e_1,
	e_m,
	e_g,
	e_p,
	e_S,
	e_f,
	e_P,
	e_ac
}					e_options;

typedef struct		s_file_info
{
	struct stat		stat;
	struct stat		lstat;
	ssize_t			xattr;
	char			*options;
	char			*path;
	char			*name;
	char			empty;
}					t_file;

typedef struct		s_page_info
{
	int				columns;
	int				num_pages;
	int				num_files;
	int				num_rows;
}					t_pages;

void				ft_usage(char option);
void				page_printer(t_pages *pages, int row, t_file *file,
								t_btree *root);
void				print_pages(t_btree *root);
int					btree_num_nodes_cmp(t_btree *root);
void				print_extra(t_file *file);
char				*path_maker(char *path, char *file);
t_nth				*nth_maker(int num);
int					is_executable(int mode);
t_file				*file_maker(char *options, char *path);
char				*get_options(int argc, char *argv[]);
void				ft_error(char *message);
void				get_args(int argc, char *argv[], char *options,
								t_btree **dirs);
void				get_files(void *item);
void				printer(t_btree *root, char *options, char *path);
void				add_directory(t_list **directoires, char *name);
void				insert_in_tree(t_btree **root, t_file *file, char *options);
void				free_item(void *item);
int					cmp_ascii(void *a, void *b);
int					cmp_time(void *a, void *b);
int					cmp_unorderd(void *a, void *b);
int					cmp_size(void *a, void *b);
int					cmp_params(void *a, void *b);
void				permission_denied(char *options, char *path);
void				print_l(void *tree_file);
void				print_name(void *file);
void				file_arg(char *path, t_btree **root, char *options);
void				free_item_name(void *item);

#endif
