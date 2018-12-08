#include "client.h"

int		send_file(int sockfd, char *cmd)
{
	struct stat st;
	int			fd;
	void		*file;
	int			len;

	if (-1 == (fd = open(cmd + 4, O_RDONLY)))
		return (ft_printf("Could not open file\n"));
	X(fstat(fd, &st));
	Xv((file = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)));
	len = ft_strlen(cmd);
	cmd[len] = '\n';
	X(write(sockfd, "put\n", 4));
	X(write(sockfd, cmd, len + 1));
	X(write(sockfd, &st.st_size, sizeof(off_t)));
	X(write(sockfd, (char*)file, st.st_size));
	X(munmap(file, st.st_size));
	X(close(fd));
	return (0);
}
