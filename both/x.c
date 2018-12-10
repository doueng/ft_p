#include "../libft/libft.h"
#include <stdio.h>
#include <errno.h>

int	x_int(int res, char *file, int line)
{
	if (res == -1)
	{
		ft_printf("file: %s\nline: %d\n", file, line);
		perror(strerror(errno));
		exit (1);
	}
	return (res);
}

void	*x_void(void *res, char *file, int line)
{
	if (res == NULL)
	{
		ft_printf("file: %s\nline: %d\n", file, line);
		perror(strerror(errno));
		exit (1);
	}
	return (res);
}
