CLIENT=src_client
SERVER=src_server
MAKE=@bear gmake -s

all:
	$(MAKE) -C $(CLIENT)
	$(MAKE) -C $(SERVER)

fclean:
	$(MAKE) fclean -C $(CLIENT)
	$(MAKE) fclean -C $(SERVER)

clean:
	$(MAKE) clean -C $(CLIENT)
	$(MAKE) clean -C $(SERVER)
re:
	$(MAKE) re -C $(CLIENT)
	$(MAKE) re -C $(SERVER)
