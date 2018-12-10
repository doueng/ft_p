/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:39:24 by dengstra          #+#    #+#             */
/*   Updated: 2017/09/10 13:43:52 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	has_acl(char *path)
{
	acl_t		acl;
	acl_entry_t tmp;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &tmp) < 0)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (acl)
	{
		acl_free(acl);
		return (1);
	}
	return (0);
}

void		print_extra(t_file *file)
{
	if (file->xattr > 0)
		ft_putstr("@ ");
	else if (has_acl(file->path))
		ft_putstr("+ ");
	else
		ft_putstr("  ");
}
