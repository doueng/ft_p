#include "client.h"

void	connect_to_srv(int sockfd, char *address, int port)
{
	struct sockaddr_in	servaddr;
	int					ret;

	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	if (-1 == (ret = inet_pton(AF_INET, address, &servaddr.sin_addr)))
		ft_errormsg("inet_pton failed");
	if (ret == 0)
		ft_putendl("Could not parse address defaulting to localhost");
	if (-1 == (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))))
		ft_errormsg("Could not connect to the host");
}
