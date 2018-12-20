#ifndef BOTH_H
# define BOTH_H
# include "../libft/libft.h"
# include <sys/socket.h>
# include <netdb.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>


# define Xv(res)	(x_void(res,__FILE__,__LINE__))
# define X(res)		(x_int(res,__FILE__,__LINE__))

# define MAXLINE 4096
# define END_MSG "\n\r\n\r"
# define CMD_LEN 6

void	ft_errormsg(char *msg);
char	*add_to_cwd(char *filename);
void	send_msg(int sockfd, char *msg);
char	*get_msg(int sockfd);
void	*get_file_mmap(char *filename, uint32_t *size);
void	write_to_file(int cfd, char *filename, uint32_t filesize);
char	*double_str_size(char *curr, int size);
void	ft_error(char *file, int line);
int		get_socket(void);
int		x_int(int res, char *file, int line);
void	*x_void(void *res, char *file, int line);

#endif
