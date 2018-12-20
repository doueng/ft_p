#ifndef SERVER_H_
# define SERVER_H_

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>
# include <dirent.h>

# define MAXLINE 4096

typedef struct	s_env
{
	char		*ls_path;
	char		*tmp_path;
}				t_env;

int		start_listening(int port);
char		*cmd_rmdir(char *arg);
char	*cmd_mkdir(char *arg);
char	*cmd_cd(char *arg);
char	*cmd_ls(char *arg, t_env *env);
char	*cmd_pwd(void);
char	*cmd_put(int cfd, char *arg);
char	*cmd_get(int cfd, char *arg);
#endif
