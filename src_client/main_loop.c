#include "client.h"

int		sender(int sockfd, char *cmd)
{
	if (0 == ft_strncmp(cmd, "put", 3))
		return (send_file(sockfd, cmd));
	else
		return (send_cmd(sockfd, cmd));
}

void	prompt(void)
{
	ft_printf("Server :::  ");
}

void	main_loop(int sockfd)
{
	char	*cmd;
	char	*trimmed_cmd;
	int		ret;

	cmd = NULL;
	prompt();
	while ((ret = get_next_line(0, &cmd)))
	{
		X(ret);
		trimmed_cmd = ft_strtrim(cmd);
		if (0 == sender(sockfd, trimmed_cmd))
			print_answer(sockfd);
		free(trimmed_cmd);
		free(cmd);
		cmd = NULL;
		prompt();
	}
}
