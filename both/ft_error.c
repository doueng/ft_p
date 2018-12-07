#include "both.h"

void	ft_error(char *file, int line)
{
	ft_printf("Error:\n\tFile: %s\n\tLine: %d", file, line);
	exit(-1);
}
