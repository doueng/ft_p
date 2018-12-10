#include "client.h"

static void	send_one_arg(int sockfd, char *tline)
{
	int len;

	len = ft_strlen(tline) + 1;
	X(write(sockfd, &len, 4));
	X(write(sockfd, tline, len));
}

static void	send_empty_arg(int sockfd)
{
	int len;

	len = 0;
	X(write(sockfd, &len, 4));
}

void		send_arg(int sockfd, char *line)
{
	char 		*tline;

	if (!line)
	{
		send_empty_arg(sockfd);
		return ;
	}
	Xv((tline = ft_strtrim(line)));
	if (*tline == 0)
		send_empty_arg(sockfd);
	else
		send_one_arg(sockfd, tline);
	free(tline);
}
