#include "client.h"

int		send_cmd(int sockfd, char *cmd)
{
	uint32_t len;

	len = ft_strlen(cmd);
	cmd[len] = '\n';
	X(write(sockfd, cmd, len + 1));
	return (0);
}
