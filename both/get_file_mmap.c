#include "both.h"

void		*get_file_mmap(char *filename, uint32_t *size)
{
	struct stat st;
	void		*file;
	int			fd;

	if (-1 == (fd = open(filename, O_RDONLY)))
		return (NULL);
	X(fstat(fd, &st));
	*size = st.st_size;
	Xv((file = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)));
	/* X(close(fd)); WTF!!!! */
	return (file);
}
