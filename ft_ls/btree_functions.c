/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:23:43 by douglas           #+#    #+#             */
/*   Updated: 2017/09/10 15:19:09 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_item(void *item)
{
	free(((t_file*)item)->path);
	free(((t_file*)item)->name);
	free(item);
}

void		free_item_name(void *item)
{
	free(((t_file*)item)->name);
	free(item);
}

void		insert_in_tree(t_btree **root, t_file *file, char *options)
{
	if (options[e_f])
		btree_insert(root, file, cmp_unorderd);
	else if (options[e_S])
		btree_insert(root, file, cmp_size);
	else if (options[e_t])
		btree_insert(root, file, cmp_time);
	else
		btree_insert(root, file, cmp_ascii);
}

int			btree_num_nodes_cmp(t_btree *root)
{
	t_file *file;

	file = ((t_file*)root->item);
	return (btree_num_nodes(root->left) + btree_num_nodes(root->right) +
		((file->name[0] == '.' && file->options[e_a] != 'a') ? 0 : 1));
}
