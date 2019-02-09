/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_cwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:02 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

char	*add_to_cwd(char *filename)
{
	char *full_path;
	char *add_slash;

	add_slash = XV(ft_strjoin("/", filename));
	full_path = XV(ft_strjoinfree(1, (XV(getcwd(NULL, 0))), 1, add_slash));
	return (full_path);
}
