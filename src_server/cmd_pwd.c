#include "server.h"

char	*cmd_pwd(void)
{
	char *cwd;

	Xv((cwd = ft_strnew(1000)));
	Xv((cwd = getcwd(cwd, 1000)));
	return (cwd);
}
