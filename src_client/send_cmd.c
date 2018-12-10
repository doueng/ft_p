#include "client.h"

static int	cmd_len(char *line)
{
	int len;

	len = 0;
	while (*line && *line++ != ' ' && len <= 5)
		len++;
	return (len);
}

int		send_cmd(int sockfd, char *line)
{
	char		cmd[5];
	int			len;

	len = cmd_len(line);
	if (len > 5)
		return (ft_putstr("Invalid command\n"));
	ft_bzero(cmd, 5);
	ft_strncpy(cmd, line, len);
	X(write(sockfd, cmd, 5));
	send_arg(sockfd, line + len);
	return (0);
}
