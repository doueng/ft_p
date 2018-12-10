#include "client.h"

int		get_file(int sockfd, char *line)
{
	char		*filename;
	uint32_t	filesize;

	filename = line + 4;
	send_cmd(sockfd, line);
	send_arg(sockfd, filename);
	X(read(sockfd, &filesize, 4));
	write_to_file(sockfd, filename, filesize);
	return (0);
}
