/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:20:49 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/08 20:20:50 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	prompt(void)
{
	ft_putstr(BOLD_TEXT);
	ft_print_color("client", CYAN_COLOR);
	ft_putstr(" 👉  ");
	ft_putstr(NORMAL_COLOR);
}

static void	main_loop(int sockfd)
{
	char	*line;
	t_env	env;

	prompt();
	while ((line = get_line(STDIN_FILENO)))
	{
		get_env(&env, line);
		if (0 == sender(sockfd, &env))
			print_response(sockfd);
		if (env.args)
			free(env.args);
		free(env.line);
		if (env.cmd == QUIT)
			break ;
		prompt();
	}
}

int			main(int argc, char *argv[])
{
	int					sockfd;

	/* signal(SIGINT, SIG_IGN); */
	if (argc != 3)
		return (ft_putstr("Usage: ./client <address> <port>\n"));
	sockfd = get_socket();
	connect_to_srv(sockfd, argv[1], ft_atoi(argv[2]));
	main_loop(sockfd);
	return (0);
}
