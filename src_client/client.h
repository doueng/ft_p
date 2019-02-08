/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:45 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLIENT_H
# define __CLIENT_H

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>

# define PORT 1800
# define MAXLINE 4096

typedef struct		s_env
{
	int8_t			cmd;
	char			*args;
	char			*line;
}					t_env;


int		send_cmd(int sockfd, t_env *env);
void	send_arg(int sockfd, t_env *env);
int		get_file(int sockfd, t_env *env);
int		send_file(int sockfd, t_env *env);
void	print_response(int sockfd);
void	connect_to_srv(int sockfd, char *address, int port);
void	main_loop(int sockfd);

#endif
