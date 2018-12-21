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
	X(close(fd));
	return (str);
}

char		*cmd_ls(t_env *env)
{
	pid_t	pid;
	int		fd;
	char	*arg;
	char	*full_arg;

	arg = env->arg;
	full_arg = Xv(ft_strjoin("ft_ls ", arg ? arg : ""));
	X((pid = fork()));
	if (pid == 0)
	{
		fd = open(env->tmp_path, O_CREAT | O_RDWR | O_TRUNC | O_SHLOCK);
		X(dup2(fd, STDOUT_FILENO));
		X(close(fd));
		exit(execv(env->ls_path, ft_strsplit(full_arg, ' ')));
	}
	else
	{
		wait(&pid);
		free(arg);
		free(full_arg);
	}
	return (file_to_str(env->tmp_path));
}
