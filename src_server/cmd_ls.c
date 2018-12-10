#include "server.h"

static char	*file_to_str(char *path)
{
	struct stat st;
	char		*str;
	int			fd;

	fd = X(open(path, O_RDONLY));
	X(fstat(fd, &st));
	Xv((str = ft_strnew(st.st_size)));
	X(read(fd, str, st.st_size));
	return (str);
}

char		*cmd_ls(int cfd)
{
	pid_t	pid;
	int		ret;
	int		fd;
	char	*msg;

	X((pid = fork()));
	fd = 0;
	if (pid == 0)
	{
		fd = open("tmp", O_CREAT | O_RDWR | O_TRUNC);
		msg = get_msg(cfd);
		dup2(fd, 1);
		ret = execl("./ft_ls", "ft_ls", msg, NULL);
		close(fd);
		exit(ret);
	}
	else
		wait(&pid);
	return (file_to_str("tmp"));
}
