/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_listening.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:42 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:56 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		start_listening(int port)
{
	struct sockaddr_in	servaddr;
	int					lfd;

	X((lfd = get_socket()));
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	X(bind(lfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
	X(listen(lfd, 42));
	return (lfd);
}
