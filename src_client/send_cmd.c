#include "client.h"

static int	cmd_len(char *line)
{
	int len;

	len = 0;
	while (*line && *line++ != ' ')
		len++;
	return (len);
}

int		send_cmd(int sockfd, char *line)
{
	char		cmd[CMD_LEN];
	int			len;

	len = cmd_len(line);
	if (len > CMD_LEN)
		return (ft_putstr("Invalid command\n"));
	ft_bzero(cmd, CMD_LEN);
	ft_strncpy(cmd, line, len);
	X(write(sockfd, cmd, CMD_LEN));
	send_arg(sockfd, line + len);
	return (0);
}
