CLIENT=src_client
SERVER=src_server
LIBFT=libft
FT_LS=src_ft_ls
MAKE=make


all: client server
	/bin/rm -f ./root/.gitkeep

client: $(CLIENT)
	$(MAKE) -C $(CLIENT)

server:
	$(MAKE) -C $(SERVER)

fclean:
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(FT_LS)
	$(MAKE) fclean -C $(CLIENT)
	$(MAKE) fclean -C $(SERVER)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(FT_LS)
	$(MAKE) clean -C $(CLIENT)
	$(MAKE) clean -C $(SERVER)

re:	fclean all

.PHONY: client server all clean fclean re
