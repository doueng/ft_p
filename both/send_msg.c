#include "both.h"

void	send_msg(int sockfd, char *msg)
{
	int len;

	len = ft_strlen(msg) + 1;
	X(write(sockfd, &len, 4));
	X(write(sockfd, msg, len));
}
