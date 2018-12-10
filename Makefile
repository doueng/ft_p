CLIENT=src_client
SERVER=src_server
LIBFT=libft
FT_LS=ft_ls
MAKE=@bear gmake -s

all:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(FT_LS)
	$(MAKE) -C $(CLIENT)
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

.PHONY: all clean fclean re
