#include "server.h"

char		*cmd_cd(char *arg)
{
	char	*curr_path;
	char	*new_path;
	char	*full_new_path;

	if (!(new_path = arg))
		return (ft_strdup("Usage: cd <path>"));
	Xv((curr_path = getcwd(NULL, 0)));
	if (-1 == chdir(new_path))
		return (ft_strdup("Could not change directory"));
	Xv((full_new_path = getcwd(NULL, 0)));
	free(new_path);
	if (ft_strstr(full_new_path, "/data"))
	{
		free(curr_path);
		return (full_new_path);
	}
	else
	{
		X(chdir(curr_path));
		free(full_new_path);
		free(curr_path);
		return (ft_strdup("Cannot move outside the data directory"));
	}
}
