/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:27:40 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERVER_H
# define __SERVER_H

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>
# include <dirent.h>

# define MAXLINE 4096

typedef struct	s_env
{
	char		*root;
	char		*ls_path;
	char		*tmp_path;
	char		*arg;
	int			cfd;
}				t_env;

char			*cmd_help(t_env *env);
int				start_listening(int port);
char			*cmd_cd(t_env *env);
char			*cmd_ls(t_env *env);
char			*cmd_pwd(t_env *env);
char			*cmd_get(t_env *env);
char			*cmd_put(t_env *env);
char			*cmd_rmdir(t_env *env);
char			*cmd_mkdir(t_env *env);
char			*cmd_quit(t_env *env);
#endif
