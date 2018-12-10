#ifndef SERVER_H_
# define SERVER_H_

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>
# include <dirent.h>

# define PORT 1800
# define MAXLINE 4096

char	*cmd_ls(int cfd);
char	*cmd_pwd(void);
char	*cmd_put(int cfd);
char	*cmd_get(int cfd);
#endif
