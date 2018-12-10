#include "both.h"

char	*get_msg(int sockfd)
{
	char		*msg;
	uint32_t	len;

	X(recv(sockfd, &len, 4, MSG_WAITALL));
	if (len == 0)
		return (NULL);
	Xv((msg = ft_strnew(len)));
	X(recv(sockfd, msg, len, MSG_WAITALL));
	return (msg);
}
