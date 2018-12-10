/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pages_ini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:45:23 by dengstra          #+#    #+#             */
/*   Updated: 2017/09/10 15:49:45 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_columns(void)
{
	struct winsize	ws;
	int				fd;

	if (0 > (fd = open("/dev/tty", O_RDONLY)))
		perror(strerror(errno));
	if (0 > ioctl(fd, TIOCGWINSZ, &ws))
		perror(strerror(errno));
	close(fd);
	return (ws.ws_col);
}

static int		get_longest_name(t_btree *root)
{
	int len;
	int tmp;

	len = ft_strlen(((t_file*)root->item)->name);
	tmp = 0;
	if (root->left)
		tmp = get_longest_name(root->left);
	len = (tmp > len) ? tmp : len;
	if (root->right)
		tmp = get_longest_name(root->right);
	len = (tmp > len) ? tmp : len;
	return (len);
}

static t_pages	*get_pages(t_btree *root)
{
	t_pages *pages;
	char	*options;

	options = (char*)((t_file*)root->item)->options;
	if (!(pages = (t_pages*)malloc(sizeof(t_pages))))
		ft_error("Malloc failed");
	pages->columns = get_columns();
	pages->num_pages = pages->columns / (get_longest_name(root) + 1);
	if (pages->num_pages == 0)
		pages->num_pages = 1;
	pages->num_files = btree_num_nodes_cmp(root);
	pages->num_rows = pages->num_files / pages->num_pages + 1;
	return (pages);
}

void			print_pages(t_btree *root)
{
	page_printer(get_pages(root), 0, NULL, root);
}
