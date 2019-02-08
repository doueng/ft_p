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
	/* char	*curr_path; */
	/* char	*new_path; */
	/* int		rv; */

	/* if (!dir) */
	/* 	return (-1); */
	/* if (*dir == '/') */
	/* 	return (-1); */
	/* Xv((curr_path = getcwd(NULL, 0))); */
	/* if (-1 == chdir(dir)) */
	/* { */
	/* 	free(curr_path); */
	/* 	return (-1); */
	/* } */
	/* rv = 0; */
	/* Xv((new_path = getcwd(NULL, 0))); */
	/* if (ft_strlen(server_data_path) >= ft_strlen(new_path)) */
	/* 	rv = -1; */
	/* X(chdir(curr_path)); */
	/* free(curr_path); */
	/* free(new_path); */
	/* return (rv); */
}
