#include "both.h"

void	send_msg(int sockfd, char *msg)
{
	uint32_t len;

	len = ft_strlen(msg);
	X(write(sockfd, &len, 4));
	X(write(sockfd, msg, len));
}
