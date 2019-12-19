# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose <mjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 10:39:14 by mjose             #+#    #+#              #
#    Updated: 2018/10/31 06:10:11 by mjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = libft.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CLEAR_LINE = \033[2K
BEGIN_LINE = \033[A

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

INC_PATH = ./includes/
SRC_PATH = ./sources/
OBJ_PATH = ./binaries/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

INC_NAME = libft.h get_next_line.h
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_iswhitespace.c ft_toupper.c ft_tolower.c \
	ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c \
	ft_putnbr.c ft_putendl_fd.c ft_putendl.c ft_strclr.c ft_strequ.c \
	ft_strnequ.c ft_striter.c ft_striteri.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_stralloc.c ft_strmap.c ft_strmapi.c \
	ft_strjoin.c ft_strsub.c ft_strtrim.c ft_countparts.c ft_partlen.c \
	ft_strsplit.c ft_intlen.c ft_itoa.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_printlst.c ft_absolut.c ft_sqrt.c get_next_line.c \
	ft_strreplace.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)
	@echo -n

$(NAME): $(OBJ)
	@echo
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(CLEAR_LINE)$(WAC)LIBRARY STATUS:\t\t\t$(OKC)Ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(CLEAR_LINE)$(WAC)LIBRARY BINARIES:\t\t$(NOC)Making binary...\t$(OKC)$@$(NOC)$(BEGIN_LINE)"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS)  $(INC) -o $@ -c $<
	@echo "$(CLEAR_LINE)$(WAC)LIBRARY BINARIES:\t\t$(OKC)Ready$(NOC)$(BEGIN_LINE)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)LIBRARY:\t\t\t$(ERC)Binaries folder removed.$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(WAC)LIBRARY:\t\t\t$(ERC)Library removed.$(NOC)"

re: fclean all
