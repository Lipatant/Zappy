##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile of Zappy
##

GUI_DIRECTORY	=	GUI
GUI_EXECUTABLE	=	zappy_gui

SERVER_DIRECTORY	=	server
SERVER_EXECUTABLE	=	zappy_server

AI_EXEC_FILE	=	ai_exe
AI_EXECUTABLE	=	zappy_ai

all:	$(GUI_EXECUTABLE) $(SERVER_EXECUTABLE) $(AI_EXECUTABLE)

$(GUI_EXECUTABLE):
	make $(GUI_EXECUTABLE) -C $(GUI_DIRECTORY)
	cp $(GUI_DIRECTORY)/$(GUI_EXECUTABLE) .

$(SERVER_EXECUTABLE):
	make $(SERVER_EXECUTABLE) -C $(SERVER_DIRECTORY)

$(AI_EXECUTABLE):
	cp $(AI_EXEC_FILE) $(AI_EXECUTABLE)

clean:
	@make clean -C $(GUI_DIRECTORY)
	@make clean -C $(SERVER_DIRECTORY)

fclean:
	@rm -f $(AI_EXECUTABLE)
	@rm -f $(GUI_EXECUTABLE)
	@rm -f $(SERVER_EXECUTABLE)
	@make fclean -C $(GUI_DIRECTORY)
	@make fclean -C $(SERVER_DIRECTORY)

re:	fclean all

server_debug:
	@cd $(SERVER_DIRECTORY) && make debug

.PHONY: all fclean clean re server server_debug
.PHONY: $(GUI_EXECUTABLE) $(SERVER_EXECUTABLE) $(AI_EXECUTABLE)
