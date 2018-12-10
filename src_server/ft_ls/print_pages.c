/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:41:09 by douglas           #+#    #+#             */
/*   Updated: 2017/09/10 15:47:21 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		put_padding(t_file *file, int page_width)
{
	int		width;
	int		mode;

	mode = file->stat.st_mode;
	width = page_width - ft_strlen(file->name);
	width = (width <= 0) ? 1 : width;
	width -= (file->options[e_p] && S_ISDIR(mode)) ? 1 : 0;
	while (width--)
		ft_putchar(' ');
}

void			page_printer(t_pages *pages, int row, t_file *file,
								t_btree *root)
{
	t_nth	*nth;
	int		i;

	while (row < pages->num_rows)
	{
		i = row++;
		while (i < pages->num_files)
		{
			nth = nth_maker(i);
			file = (t_file*)btree_get_nth(root, nth)->node->item;
			if (file->name[0] == '.' && file->options[e_a] != 'a')
				i++;
			else
			{
				print_name(file);
				put_padding(file, pages->columns / pages->num_pages);
				i += pages->num_rows;
			}
			free(nth);
		}
		ft_putchar('\n');
	}
	free(pages);
}
