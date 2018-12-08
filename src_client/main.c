#include "client.h"

int main(int argc, char *argv[])
{
	int					sockfd;

	if (argc != 2)
		return (ft_printf("wrong number args\n"));
	sockfd = get_socket();
	connect_to_srv(sockfd, argv[1]);
	main_loop(sockfd);
	return (0);
}
