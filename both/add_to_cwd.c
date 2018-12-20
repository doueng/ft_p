#include "both.h"

char	*add_to_cwd(char *filename)
{
	char *full_path;
	char *add_slash;

	add_slash = Xv(ft_strjoin("/", filename));
	full_path = Xv(ft_strjoin((Xv(getcwd(NULL, 0))), add_slash));
	free(add_slash);
	return (full_path);
}
