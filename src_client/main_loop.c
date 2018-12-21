#include "client.h"

int		sender(int sockfd, char *line)
{
	if (ft_strnequ(line, "put", 3))
		return (send_file(sockfd, line));
	else if (ft_strnequ(line, "get", 3))
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

char	*get_line(int fd)
{
	char	*line;
	char	buff;
	int		len;
	int		i;

	len = 100;
	i = 0;
	Xv((line = ft_strnew(len)));
	while (X(read(fd, &buff, 1)))
	{
		if (buff == '\n')
			break ;
		if (len - 1 == i)
		{
			double_str_size(line, len);
			len *= 2;
		}
		line[i] = buff;
		i++;
	}
	return (line);
}

void	main_loop(int sockfd)
{
	char	*line;
	char	*trimmed_cmd;

	line = NULL;
	prompt();
	while ((line = get_line(STDIN_FILENO)))
	{
		trimmed_cmd = ft_strtrim(line);
		if (0 == sender(sockfd, trimmed_cmd))
			print_response(sockfd);
		if (ft_strequ(trimmed_cmd, "quit"))
		{
			free(trimmed_cmd);
			break ;
		}
		free(trimmed_cmd);
		free(line);
		line = NULL;
		prompt();
	}
}
