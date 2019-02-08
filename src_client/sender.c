#include "client.h"

static void	send_arg(int sockfd, t_env *env)
{
	uint32_t	len;

	len = 0;
	if (!env->args)
		X(write(sockfd, &len, NUM_BYTES_CMD));
	else
		send_msg(sockfd, env->args);
}


static int	send_file(int sockfd, t_env *env)
{
	void		*file;
	uint64_t	filesize;

	if (NULL == (file = get_file_mmap(env->args, &filesize)))
		return (ft_printf("Could not open file\n"));
	send_cmd(sockfd, env);
	X(write(sockfd, &filesize, NUM_BYTES_FILESIZE));
	X(write(sockfd, file, filesize));
	X(munmap(file, filesize));
	return (0);
}

int		send_cmd(int sockfd, t_env *env)
{
	X(write(sockfd, &env->cmd, 1));
	send_arg(sockfd, env);
	return (0);
}

int			sender(int sockfd, t_env *env)
{
	if (env->cmd == -1)
	{
		ft_putstr_fd("Invalid command\n", 2);
		return (-1);
	}
	if (env->cmd == PUT)
		return (send_file(sockfd, env));
	else if (env->cmd == GET)
		return (get_file(sockfd, env));
	return (send_cmd(sockfd, env));
}
