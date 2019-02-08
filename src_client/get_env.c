#include "client.h"

static char	get_cmd_code(char *line)
{
	char	cmd_code;
	char	*cmd_end;

	cmd_code = -1;
	if ((cmd_end = ft_strchr(line, ' ')))
		*cmd_end = 0;
	cmd_code = (ft_strequ("cd", line)) ? CD : cmd_code;
	cmd_code = (ft_strequ("ls", line)) ? LS : cmd_code;
	cmd_code = (ft_strequ("pwd", line)) ? PWD : cmd_code;
	cmd_code = (ft_strequ("get", line)) ? GET : cmd_code;
	cmd_code = (ft_strequ("put", line)) ? PUT : cmd_code;
	cmd_code = (ft_strequ("mkdir", line)) ? MKDIR : cmd_code;
	cmd_code = (ft_strequ("rmdir", line)) ? RMDIR : cmd_code;
	cmd_code = (ft_strequ("quit", line)) ? QUIT : cmd_code;
	cmd_code = (ft_strequ("help", line)) ? HELP : cmd_code;
	return (cmd_code);
}

void		get_env(t_env *env, char *line)
{
	char *tline;

	ft_bzero(env, sizeof(*env));
	tline = Xv(ft_strtrim(line));
	free(line);
	if ((env->args = ft_strchr(tline, ' ')))
		env->args = ft_strtrim(env->args);
	env->cmd = get_cmd_code(tline);
	env->line = tline;
}
