/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:05 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		send_arg(int sockfd, t_env *env)
{
	uint32_t	len;

	len = 0;
	if (!env->args)
		X(write(sockfd, &len, NUM_BYTES_CMD));
	else
		send_msg(sockfd, env->args);
}
