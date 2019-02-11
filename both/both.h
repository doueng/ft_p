/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:26:10 by dengstra          #+#    #+#             */
/*   Updated: 2019/02/07 15:27:59 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H
# include "../libft/libft.h"
# include <sys/socket.h>
# include <netdb.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>

# define XV(res)	(x_void(res,__FILE__,__LINE__))
# define X(res)		(x_int(res,__FILE__,__LINE__))

enum {
	CD,
	LS,
	PWD,
	GET,
	PUT,
	MKDIR,
	RMDIR,
	QUIT,
	HELP,
	NUM_CMDS,
	INVALID_PATH
};

# define NUM_BYTES_FILESIZE 8
# define NUM_BYTES_CMD 4

void	write_to_file(int cfd, char *filename, uint64_t filesize);
int		check_path(char *server_data_path, char *file_or_dir);
void	*get_file_mmap(char *filename, uint64_t *size);
void	ft_errormsg(char *msg);
char	*add_to_cwd(char *filename);
void	send_msg(int sockfd, char *msg);
char	*get_msg(int sockfd);
int		get_socket(void);
int		x_int(int res, char *file, int line);
void	*x_void(void *res, char *file, int line);

#endif
