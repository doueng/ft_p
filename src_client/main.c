#include "client.h"

int main(int argc, char *argv[])
{
	int					sockfd;

	/* signal(SIGINT, SIG_IGN); */
	if (argc != 3)
		return (ft_putstr("Usage: ./client <address> <port>\n"));
	sockfd = get_socket();
	connect_to_srv(sockfd, argv[1], ft_atoi(argv[2]));
	main_loop(sockfd);
	return (0);
}
