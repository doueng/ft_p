#include "server.h"

char	*cmd_quit(t_env *env)
{
	ft_printf("Socket %d disconnected\n", env->cfd);
	return (Xv(ft_strdup("Connection terminated")));
}
