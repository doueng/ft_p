#include "server.h"

char	*cmd_get(t_env *env)
{
	char		*filename;
	uint64_t	filesize;
	void		*file;

	filename = env->arg;
	if (NULL == (file = get_file_mmap(filename, &filesize)))
		return (Xv(ft_strdup("Could not open file\n")));
	write(env->cfd, &filesize, 8);
	X(write(env->cfd, file, filesize));
	X(munmap(file, filesize));
	return (Xv(ft_strdup("File downloading!!!")));
}
// free msg
