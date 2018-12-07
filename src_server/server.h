#ifndef SERVER_H_
# define SERVER_H_

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>
# include <dirent.h>

char	*cmd_ls(void);
char	*cmd_pwd(void);

# define PORT 1800
# define MAXLINE 4096
#endif
