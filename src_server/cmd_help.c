
#include "server.h"

char	*cmd_help(t_env *env)
{
	char *a;
	char *b;
	char *c;
	char *help;
	char *tmp;

	(void)env;
	a = "Commands:\n\tcd folder\n\tls -options <file or folder>\n\tpwd\n";
	b = "\tget file/folder\n\tput file/folder\n";
	c = "\tmkdir name\n\trmdir name\n\tquit\n\thelp";
	tmp = Xv(ft_strjoin(a, b));
	help = Xv(ft_strjoin(tmp, c));
	free(tmp);
	return (help);
}
