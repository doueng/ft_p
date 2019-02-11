/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:50 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	connect_to_srv(int sockfd, char *address, int port)
{
	struct sockaddr_in	servaddr;
	int					ret;

	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	X(ret = inet_pton(AF_INET, address, &servaddr.sin_addr));
	if (ret == 0)
		ft_putendl_fd("Could not parse address defaulting to localhost", 2);
	X(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
}
