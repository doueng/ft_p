/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:33:01 by douglas           #+#    #+#             */
/*   Updated: 2017/09/11 15:39:05 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_option(char *options, char option)
{
	if (!ft_strchr("lRartG1gpSf-", option))
		ft_usage(option);
	(option == 'l') ? options[e_l] = 'l' : 0;
	(option == 'R') ? options[e_R] = 'R' : 0;
	(option == 'a') ? options[e_a] = 'a' : 0;
	(option == 'r') ? options[e_r] = 'r' : 0;
	(option == 't') ? options[e_t] = 't' : 0;
	(option == 'G') ? options[e_G] = 'G' : 0;
	(option == '1') ? options[e_1] = '1' : 0;
	if (option == 'g')
	{
		options[e_g] = 'g';
		options[e_l] = 'l';
	}
	(option == 'p') ? options[e_p] = 'p' : 0;
	(option == 'S') ? options[e_S] = 'S' : 0;
	if (option == 'f')
	{
		options[e_f] = 'f';
		options[e_a] = 'a';
	}
}

char		*get_options(int argc, char *argv[])
{
	char	*options;
	int		i;
	char	option;

	if (!(options = ft_strnew(15)))
		ft_error("Malloc failed");
	while (--argc > 0)
	{
		if (argv[argc][0] != '-' || ft_strequ("-", argv[argc]))
		{
			options[e_ac]++;
			continue ;
		}
		i = 0;
		while ((option = argv[argc][++i]))
			add_option(options, option);
		if (i == 1)
			ft_usage(option);
	}
	return (options);
}
