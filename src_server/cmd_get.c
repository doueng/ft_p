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

	filename = env->arg;
	if (filename == NULL && -1 == check_path(env->server_data_path, filename))
		return (ft_strdup("Invalid argument"));
	if (NULL == (file = get_file_mmap(filename, &filesize)))
		return (Xv(ft_strdup("Could not open file\n")));
	write(env->cfd, &filesize, 8);
	X(write(env->cfd, file, filesize));
	X(munmap(file, filesize));
	return (Xv(ft_strdup("File downloading!!!")));
}
