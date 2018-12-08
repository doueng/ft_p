#include "client.h"

void	print_answer(int sockfd)
{
	char	*answer;
	int		len;

	read(sockfd, &len, 4);
	Xv(answer = ft_strnew(len));
	read(sockfd, answer, len);
	ft_printf("%s\n", answer);
	free(answer);
}
