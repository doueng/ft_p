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
	if (filename == NULL && -1 == check_path(env->server_data_path, filename))
		return (ft_strdup("Invalid argument"));
	ft_printf("filename: (%s)\n", filename);
	X(recv(env->cfd, &filesize, NUM_BYTES_FILESIZE, MSG_WAITALL));
	ft_printf("filesize: (%d)\n", filesize);
	write_to_file(env->cfd, filename, filesize);
	return (Xv(ft_strdup("File uploaded!!!!")));
}
