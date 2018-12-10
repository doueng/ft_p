#include "server.h"

char		*cmd_put(int cfd, char *arg)
{
	char		*filename;
	uint32_t	filesize;

	filename = arg;
	ft_printf("filename: (%s)\n", filename);
	X(recv(cfd, &filesize, 4, MSG_WAITALL));
	ft_printf("filesize: (%d)\n", filesize);
	write_to_file(cfd, filename, filesize);
	return (Xv(ft_strdup("File uploaded!!!!")));
}
