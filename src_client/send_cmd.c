#include "client.h"

static int	cmd_len(char *line)
{
	int len;

	len = 0;
	while (*line && *line++ != ' ')
		len++;
	return (len);
}

static char	get_cmd_code(char *line, int cmd_len)
{
	char cmd_code;

	cmd_code = -1;
	cmd_code = (ft_strnequ("cd", line, cmd_len)) ? CD : cmd_code;
	cmd_code = (ft_strnequ("ls", line, cmd_len)) ? LS : cmd_code;
	cmd_code = (ft_strnequ("pwd", line, cmd_len)) ? PWD : cmd_code;
	cmd_code = (ft_strnequ("get", line, cmd_len)) ? GET : cmd_code;
	cmd_code = (ft_strnequ("put", line, cmd_len)) ? PUT : cmd_code;
	cmd_code = (ft_strnequ("mkdir", line, cmd_len)) ? MKDIR : cmd_code;
	cmd_code = (ft_strnequ("rmdir", line, cmd_len)) ? RMDIR : cmd_code;
	cmd_code = (ft_strnequ("quit", line, cmd_len)) ? QUIT : cmd_code;
	return (cmd_code);
}

int		send_cmd(int sockfd, char *line)
{
	int		len;
	char	code;

	len = cmd_len(line);
	if (-1 == (code = get_cmd_code(line, len)))
		return (ft_putstr("Invalid command\n"));
	X(write(sockfd, &code, 1));
	send_arg(sockfd, line + len);
	return (0);
}
