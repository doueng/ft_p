#include "server.h"

char		*cmd_put(t_env *env)
{
	char		*filename;
	uint32_t	filesize;

	filename = env->arg;
	ft_printf("filename: (%s)\n", filename);
	X(recv(env->cfd, &filesize, 4, MSG_WAITALL));
	ft_printf("filesize: (%d)\n", filesize);
	write_to_file(env->cfd, filename, filesize);
	return (Xv(ft_strdup("File uploaded!!!!")));
}
