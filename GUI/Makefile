##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for GUI part of Zappy
##

# VARIABLES #

# Files
NAME	=	zappy_gui

# Directories
SRC_DIR	=	src/
BUILDDIR	= build
IDIR	=	include
DOCS	=	docs
# Flags
CPPFLAGS	=	-I./$(IDIR)
CFLAGS	=	-W -Wall -Wextra -std=c++20
LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread
GCCFLAG	=	g++ -o
DOXYGEN	=	doxygen docsressources/Doxyfile
FDEBUG	=	-g3

# CONVERTION RULES #

# Source base
SRC_BASE	=	$(shell cat make.txt | tr '\n' ' ')
SRC	=	$(shell cat $(SRC_BASE) | tr '\n' ' ')
# Objects
OBJ	=	$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

# Objects from Sources
$(BUILDDIR)/%.o: 	$(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	$(GCCFLAG) $(NAME) $(OBJ) $(LDFLAGS) $(FDEBUG)

clean:
	$(RM) -f $(OBJ)

fclean: clean doc_clean
	$(RM) -f $(NAME)

doc_clean:
	@$(RM) -r $(DOCS)

doc_html:	doc_clean
	$(DOXYGEN)

doc:	doc_html

re:	fclean all

.PHONY: all debug fclean clean re
