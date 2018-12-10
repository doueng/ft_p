#include "both.h"

// optimize
void		write_to_file(int cfd, char *filename, uint32_t filesize)
{
	int		filefd;
	char	buff;
	/* char	*mod_buff; */
	/* int		buffsize; */

	X((filefd = open(filename, O_RDWR | O_CREAT | O_TRUNC)));
	/* buffsize = 100; */
	/* Xv(mod_buff = ft_strnew(filesize % buffsize)); */
	while (filesize--)
	{
		X(read(cfd, &buff, 1));
		X(write(filefd, &buff, 1));
	}
	close(filefd);
}
