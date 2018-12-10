#ifndef CLIENT_H_
# define CLIENT_H_

# include "../libft/libft.h"
# include "../both/both.h"
# include <sys/socket.h>
# include <arpa/inet.h>

# define PORT 1800
# define MAXLINE 4096

void	print_response(int sockfd);
int		get_file(int sockfd, char *line);
void	connect_to_srv(int sockfd, char *address, int port);
int		send_file(int sockfd, char *line);
void	main_loop(int sockfd);
void	send_arg(int sockfd, char *line);
int		send_cmd(int sockfd, char *line);

#endif
