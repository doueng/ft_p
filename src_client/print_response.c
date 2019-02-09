/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:03 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	print_response(int sockfd)
{
	char	*response;
	int		len;

	X(read(sockfd, &len, 4));
	XV(response = ft_strnew(len));
	X(read(sockfd, response, len));
	ft_printf("%s\n", response);
	free(response);
}
