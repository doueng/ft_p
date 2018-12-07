#include "server.h"

char	*cmd_ls(void)
{
	DIR				*dir;
	struct dirent	*curr;
	char			*file_names;
	int				i;
	int				len;

	len = 1000;
	Xv((file_names = ft_strnew(len)));
	Xv((dir = opendir(".")));
	i = 0;
	while ((curr = readdir(dir)))
	{
		ft_memcpy(file_names + i, curr->d_name, curr->d_namlen);
		i += curr->d_namlen;
		file_names[i] = '\n';
		i++;
		if (i >= len)
		{
			file_names = double_str_size(file_names, len);
			len *= 2;
		}
	}
	file_names[i - 1] = 0;
	X(closedir(dir));
	return (file_names);
}
