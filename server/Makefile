##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SR	=	src/

SRC	=	$(shell cat make/server.txt | tr '\n' ' ')						\

SRC_UT		=	tests/Unit_tests.cpp									\

BUILDDIR	=	build

OBJ	=	$(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	$(SR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

NAME	=	zappy_server

LDFLAGS	=

IDIR	=	include

CPPFLAGS	=	-iquote ./$(IDIR)

CFLAGS	=	-W -Wall -Wextra

GCCFLAG	=	gcc -o

FDEBUG	=	-g3

LOGSFILE	=	logs.txt

CC			=	gcc

UT 			=	unit_tests

CFLAGS_UT		=	-Wall -Wextra -Werror

CPPFLAGS_UT	+=	$(CPPFLAGS)

LCRITERION	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) > $(LOGSFILE)
	@mv $(NAME) ../

debug:	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG) > $(LOGSFILE)

debug_play:	fclean debug
	clear
	valgrind --track-origins=yes ./$(NAME)

clean:
	$(RM) -f $(OBJ) > $(LOGSFILE)

fclean: clean
	$(RM) -f ../$(NAME) >> $(LOGSFILE)
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

re:	fclean all

tests_run: fclean
		$(CC) -o $(UT) $(SRC_UT) $(CFLAGS_UT) $(CPPFLAGS_UT) \
			$(LCRITERION) $(CPPFLAGS_UT)
		./$(UT)

doc:
	@doxygen docsressources/Doxyfile

.PHONY: all debug debug_play fclean clean re tests_run doc
