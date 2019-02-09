/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:21:02 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/08 20:21:03 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*cmd_help(t_env *env)
{
	char *a;
	char *b;
	char *c;
	char *help;
	char *tmp;

	(void)env;
	a = "Commands:\n\tcd folder\n\tls -options <file or folder>\n\tpwd\n";
	b = "\tget file\n\tput file\n";
	c = "\tmkdir name\n\trmdir name\n\tquit\n\thelp";
	tmp = XV(ft_strjoin(a, b));
	help = XV(ft_strjoin(tmp, c));
	free(tmp);
	return (help);
}
