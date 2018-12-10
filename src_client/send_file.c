#include "client.h"

int		send_file(int sockfd, char *line)
{
	void		*file;
	uint32_t	filesize;

	if (NULL == (file = get_file_mmap(line + 4, &filesize)))
		return (ft_printf("Could not open file\n"));
	send_cmd(sockfd, line);
	send_arg(sockfd, line + 3);
	write(sockfd, &filesize, 4);
	X(write(sockfd, file, filesize));
	X(munmap(file, filesize));
	return (0);
}
