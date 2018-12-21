#include "server.h"

char	*cmd_pwd(t_env *env)
{
	(void)env;
	return (Xv(getcwd(NULL, 0)));
}
