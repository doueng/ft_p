/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:59:31 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/09 17:59:39 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int			check_path(char *server_data_path, char *file_or_dir)
{
	char	*cwd;
	int		rv;

	if (!file_or_dir)
		return (-1);
	if (*file_or_dir == '/')
		return (-1);
	cwd = XV(getcwd(NULL, 0));
	rv = 0;
	if (ft_strequ(file_or_dir, "..") && ft_strequ(server_data_path, cwd))
		rv = -1;
	free(cwd);
	return (rv);
}
