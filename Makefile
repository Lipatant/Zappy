##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile of Zappy
##

SR	=	src/

SRC	=	$(shell cat make/zappy.txt | tr '\n' ' ')						\

SRC_UT		=	tests/Unit_tests.cpp									\

BUILDDIR = build

OBJ = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	$(SR)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	zappy

LDFLAGS	=	-lconfig++

IDIR	=	include

CPPFLAGS	=	-I./$(IDIR)

CFLAGS	=	-W -Wall -Wextra

GCCFLAG	=	g++ -o

FDEBUG	=	-g3

LOGSFILE	=	logs.txt

CC			=	g++

UT 			=	unit_tests

CFLAGS_UT		=	-std=c++17  -Wall -Wextra -Werror

CPPFLAGS_UT	+=	-I./include

LCRITERION	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) > $(LOGSFILE)

debug:	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG) > $(LOGSFILE)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(RM) -f $(OBJ) > $(LOGSFILE)

fclean: clean
	$(RM) -f $(NAME) >> $(LOGSFILE)
	@$(RM) -f $(NAME)
	@$(RM) -f $(UT)
	@$(RM) -f unit_tests
	@$(RM) -f vgcore*
	@$(RM) -f *.gcda
	@$(RM) -f *.gcno
	@$(RM) -f *~
	@$(RM) -f *.a
	@$(RM) -f *.o
	@$(RM) -f *.gch
	@$(RM) -f a.out
	@$(RM) -f coding-style-reports.log

play:	$(NAME)
	./$(NAME)

re:	fclean all

play_re: re
	./$(NAME)

tests_run: fclean
		$(CC) -o $(UT) $(SRC_UT) $(CFLAGS_UT) $(CPPFLAGS_UT) \
			$(LCRITERION) $(CPPFLAGS_UT)
		./$(UT)

server:
	@cd server && make

server_re:
	@cd server && make re

server_fclean:
	@cd server && make fclean

server_clean:
	@cd server && make clean


.PHONY: all debug debug_play fclean clean play re play_re tests_run server
.PHONY: server_re server_fclean server_clean
