#include "server.h"

char		*cmd_put(int cfd)
{
	char		*filename;
	uint32_t	filesize;

	filename = get_msg(cfd);
	ft_printf("filename: (%s)\n", filename);
	X(read(cfd, &filesize, 4));
	ft_printf("filesize: (%d)\n", filesize);
	write_to_file(cfd, filename, filesize);
	return (Xv(ft_strdup("File uploaded!!!!")));
}
