#include "client.h"

int		send_file(int sockfd, char *line)
{
	void		*file;
	uint64_t	filesize;

	if (NULL == (file = get_file_mmap(line + 4, &filesize)))
		return (ft_printf("Could not open file\n"));
	send_cmd(sockfd, line);
	write(sockfd, &filesize, 8);
	X(write(sockfd, file, filesize));
	X(munmap(file, filesize));
	return (0);
}
