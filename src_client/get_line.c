#include "client.h"

char		*get_line(int fd)
{
	char	*line;
	char	buff[2];
	char	*rev_line;

	line = ft_strnew(1);
	ft_bzero(&buff, 2);
	while (X(read(fd, &buff, 1)))
	{
		if (*buff == '\n')
			break;
		line = Xv(ft_strjoinfree(0, buff, 1, line));
	}
	rev_line = Xv(ft_strrev(line));
	return (rev_line);
}
