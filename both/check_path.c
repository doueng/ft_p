#include "both.h"

int			check_path(char *server_data_path, char *file_or_dir)
{

	char	*cwd;
	int		rv;

	if (!file_or_dir)
		return (-1);
	if (*file_or_dir == '/')
		return (-1);
	cwd = Xv(getcwd(NULL, 0));
	rv = 0;
	if (ft_strequ(file_or_dir, "..") && ft_strequ(server_data_path, cwd))
		rv = -1;
	free(cwd);
	return (rv);
}
