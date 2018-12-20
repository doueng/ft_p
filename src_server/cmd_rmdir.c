#include "server.h"
#include <errno.h>
#include <stdio.h>

char		*cmd_rmdir(char *arg)
{
	char *res;
	char *dir_path;

	dir_path = add_to_cwd(arg);
	res = (unlink(dir_path)) == -1 ? "Failed to remove " : "Removed dir ";
	free(dir_path);
	perror(strerror(errno));
	return (Xv(ft_strjoin(res, arg)));
}
