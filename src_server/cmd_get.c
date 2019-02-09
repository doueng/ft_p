/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:17 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*cmd_get(t_env *env)
{
	char		*filename;
	uint64_t	filesize;
	void		*file;
	char		*res;

	filename = env->arg;
	filesize = 0;
	res = "File downloading!!!";
	if (filename == NULL && -1 == check_path(env->root, filename))
	{
		X(write(env->cfd, &filesize, NUM_BYTES_FILESIZE));
		res = "Invalid argument";
	}
	else if (NULL == (file = get_file_mmap(filename, &filesize)))
	{
		X(write(env->cfd, &filesize, NUM_BYTES_FILESIZE));
		res = "Could not open file\n";
	}
	else
	{
		X(write(env->cfd, &filesize, NUM_BYTES_FILESIZE));
		X(write(env->cfd, file, filesize));
		X(munmap(file, filesize));
	}
	return (XV(ft_strdup(res)));
}
