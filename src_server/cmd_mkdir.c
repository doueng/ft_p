#include "server.h"

char		*cmd_mkdir(char *arg)
{
	char	*res;
	char	*new_dir_path;

	new_dir_path = add_to_cwd(arg);
	res = (mkdir(new_dir_path, 733)) == -1
		? "Failed to create "
		: "Created ";
	free(new_dir_path);
	return (Xv(ft_strjoin(res, arg)));
}
