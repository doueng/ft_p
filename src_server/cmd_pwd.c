#include "server.h"

char	*cmd_pwd(void)
{
	return (Xv(getcwd(NULL, 0)));
}
