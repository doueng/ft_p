/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:33 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void		write_to_file(int cfd, char *filename, uint64_t filesize)
{
	int		filefd;
	char	buff;

	X((filefd = open(filename, O_RDWR | O_CREAT | O_TRUNC)));
	while (filesize--)
	{
		X(read(cfd, &buff, 1));
		X(write(filefd, &buff, 1));
	}
	close(filefd);
}
