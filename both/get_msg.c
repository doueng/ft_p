/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:25 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

char	*get_msg(int sockfd)
{
	char		*msg;
	uint32_t	len;

	X(recv(sockfd, &len, NUM_BYTES_CMD, MSG_WAITALL));
	if (len == 0)
		return (NULL);
	Xv((msg = ft_strnew(len)));
	X(recv(sockfd, msg, len, MSG_WAITALL));
	return (msg);
}
