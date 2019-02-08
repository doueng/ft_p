/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:55 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		get_file(int sockfd, t_env *env)
{
	uint64_t	filesize;

	send_cmd(sockfd, env);
	X(read(sockfd, &filesize, NUM_BYTES_FILESIZE));
	write_to_file(sockfd, env->args, filesize);
	ft_printf("got file\n");
	return (0);
}
