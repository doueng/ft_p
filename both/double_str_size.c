#include "both.h"

char	*double_str_size(char *curr, int size)
{
	char *new;

	Xv((new = ft_strnew(size * 2)));
	ft_memcpy(new, curr, size);
	free(curr);
	return (new);
}
