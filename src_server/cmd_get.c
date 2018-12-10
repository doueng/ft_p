#include "server.h"

char	*cmd_get(int cfd, char *arg)
{
	char		*filename;
	uint32_t	filesize;
	void		*file;

	filename = arg;
	if (NULL == (file = get_file_mmap(filename, &filesize)))
		return (Xv(ft_strdup("Could not open file\n")));
	write(cfd, &filesize, 4);
	X(write(cfd, file, filesize));
	X(munmap(file, filesize));
	return (Xv(ft_strdup("File downloading!!!")));
}
