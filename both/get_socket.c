#include "both.h"

int	get_socket(void)
{
	struct protoent	*pe;
	int				sockfd;

	Xv((pe = getprotobyname("tcp")));
	X((sockfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)));
	return (sockfd);
}
