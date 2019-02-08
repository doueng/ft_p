/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:10 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		send_file(int sockfd, t_env *env)
{
	void		*file;
	uint64_t	filesize;

	if (NULL == (file = get_file_mmap(env->args, &filesize)))
		return (ft_printf("Could not open file\n"));
	send_cmd(sockfd, env);
	X(write(sockfd, &filesize, NUM_BYTES_FILESIZE));
	X(write(sockfd, file, filesize));
	X(munmap(file, filesize));
	return (0);
}
