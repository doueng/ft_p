#include "client.h"

void	print_response(int sockfd)
{
	char	*response;
	int		len;

	read(sockfd, &len, 4);
	Xv(response = ft_strnew(len));
	read(sockfd, response, len);
	ft_printf("%s\n", response);
	free(response);
}
