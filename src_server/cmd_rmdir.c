#include "server.h"
#include <errno.h> // remove
#include <stdio.h> // remove

char		*cmd_rmdir(t_env *env)
{
	char *res;
	char *dir_path;
	char *arg;

	arg = env->arg;
	dir_path = add_to_cwd(arg);
	res = (unlink(dir_path)) == -1 ? "Failed to remove " : "Removed dir ";
	free(dir_path);
	perror(strerror(errno)); // remove
	return (Xv(ft_strjoin(res, arg)));
}
