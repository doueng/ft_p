#ifndef CLIENT_H_
# define CLIENT_H_

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/stat.h>
# include <sys/mman.h>

# define PORT 1800
# define MAXLINE 4096

void	print_answer(int sockfd);
void	connect_to_srv(int sockfd, char *address);
int		send_cmd(int sockfd, char *cmd);
int		send_file(int sockfd, char *cmd);
void	main_loop(int sockfd);

#endif
