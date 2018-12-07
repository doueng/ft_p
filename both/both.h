#ifndef BOTH_H
# define BOTH_H
# include "../libft/libft.h"
# include <sys/socket.h>
# include <netdb.h>

# define Xv(res)	(x_void(res,__FILE__,__LINE__))
# define X(res)		(x_int(res,__FILE__,__LINE__))

# define MAXLINE 4096
# define END_MSG "\n\r\n\r"

char	*double_str_size(char *curr, int size);
void	ft_error(char *file, int line);
int		get_socket(void);
int		x_int(int res, char *file, int line);
void	*x_void(void *res, char *file, int line);

#endif
