#include "client.h"

int		sender(int sockfd, char *line)
{
	if (0 == ft_strncmp(line, "put", 3))
		return (send_file(sockfd, line));
	else if (0 == ft_strncmp(line, "get", 3))
		return (get_file(sockfd, line));
	else
		return (send_cmd(sockfd, line));
}

void	prompt(void)
{
	ft_putstr(BOLD_TEXT);
	ft_print_color("client", CYAN_COLOR);
	ft_putstr(" 👉  ");
	ft_putstr(NORMAL_COLOR);
}

void	main_loop(int sockfd)
{
	char	*line;
	char	*trimmed_cmd;
	int		ret;

	line = NULL;
	prompt();
	while ((ret = get_next_line(0, &line)))
	{
		X(ret);
		trimmed_cmd = ft_strtrim(line);
		if (0 == sender(sockfd, trimmed_cmd))
			print_response(sockfd);
		free(trimmed_cmd);
		free(line);
		line = NULL;
		if (ft_strequ(trimmed_cmd, "quit"))
			break ;
		prompt();
	}
}
