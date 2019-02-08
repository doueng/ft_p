/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:57 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		prompt(void)
{
	ft_putstr(BOLD_TEXT);
	ft_print_color("client", CYAN_COLOR);
	ft_putstr(" 👉  ");
	ft_putstr(NORMAL_COLOR);
}

void			main_loop(int sockfd)
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
