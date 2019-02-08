
#include "server.h"

char	*cmd_help(t_env *env)
{
	(void)env;
	return (Xv(ft_strdup("Commands:\n\
\tcd folder\n\
\tls -options <file or folder>\n\
\tpwd\n\
\tget file/folder\n\
\tput file/folder\n\
\tmkdir name\n\
\trmdir name\n\
\tquit\n\
\thelp")));
}
