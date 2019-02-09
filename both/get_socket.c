/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_socket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:28 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int	get_socket(void)
{
	int				sockfd;

	X((sockfd = socket(AF_INET, SOCK_STREAM, 6)));
	return (sockfd);
}
