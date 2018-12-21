#include "client.h"

int		get_file(int sockfd, char *line)
{
	char		*filename;
	uint64_t	filesize;

	filename = line + 4;
	send_cmd(sockfd, line);
	X(read(sockfd, &filesize, 8));
	write_to_file(sockfd, filename, filesize);
	return (0);
}
