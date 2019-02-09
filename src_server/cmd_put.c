/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:25 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*cmd_put(t_env *env)
{
	char		*filename;
	uint64_t	filesize;

	filename = env->arg;
	if (filename == NULL && -1 == check_path(env->root, filename))
		return (ft_strdup("Invalid argument"));
	X(recv(env->cfd, &filesize, NUM_BYTES_FILESIZE, MSG_WAITALL));
	write_to_file(env->cfd, filename, filesize);
	return (Xv(ft_strdup("File uploaded!!!!")));
}
