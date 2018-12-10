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
	str[st.st_size - 1] = 0;
	X(close(fd));
	return (str);
}

char		*cmd_ls(char *arg, t_env *env)
{
	pid_t	pid;
	int		ret;
	int		fd;

	X((pid = fork()));
	if (pid == 0)
	{
		fd = open(env->tmp_path, O_CREAT | O_RDWR | O_TRUNC);
		dup2(fd, 1);
		ret = execl(env->ls_path, "ft_ls", arg, NULL);
		X(close(fd));
		exit(ret);
	}
	else
		wait(&pid);
	return (file_to_str(env->tmp_path));
}
