#include "client.h"

void	connect_to_srv(int sockfd, char *address)
{
	struct sockaddr_in	servaddr;

	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	X(inet_pton(AF_INET, address, &servaddr.sin_addr)); // check zero, non parsable, man 3 inet
	X(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
}
