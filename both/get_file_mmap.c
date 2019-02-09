/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_mmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:23 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void		*get_file_mmap(char *filename, uint64_t *size)
{
	struct stat st;
	void		*file;
	int			fd;

	if (-1 == (fd = open(filename, O_RDONLY)))
		return (NULL);
	X(fstat(fd, &st));
	if (st.st_mode & S_IFDIR)
	{
		/* X(close(fd)); */
		return (NULL);
	}
	*size = st.st_size;
	Xv((file = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)));
	/* X(close(fd)); WTF!!!! */
	return (file);
}
