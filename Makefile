# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slenore <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:03:30 by slenore           #+#    #+#              #
#    Updated: 2019/11/01 16:53:28 by slenore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTH = libft/libft.h
INCLUDES = ft_printf.h

CC = gcc
CFLAGS =  -Wall -Wextra -Werror


LIB_FUNC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
		ft_strlen ft_strdup ft_strndup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
	   	ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi  \
		ft_isdigit ft_isalpha  ft_isascii ft_isprint ft_isalnum ft_toupper ft_tolower\
	   	ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striteri\
	  	ft_striter ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin\
		ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr\
	   	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isblank ft_isspace\
   		ft_lstnew	ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
   		ft_strndup ft_strndup_f ft_itoa_base ft_max ft_min ft_sign ft_isneg ft_ultoa\
   		ft_ultoa_base ft_revstr ft_abs\
   		ft_doubletostr

INCLUDES = libft.h

LIB_SRC =  $(patsubst  %, libft/%.c, $(LIB_FUNC))
LIB_OBJ =  $(patsubst %, %.o , $(LIB_FUNC))


PRINTF_FUNC = main ft_gett_values ft_parse_frmt ft_parse_opt1 ft_parse_opt2 ft_srmax\
            nesting_char nesting_di  nesting_pointer nesting_str  nesting_u nesting_x\
            printing\

PRINTF_SRC =  $(patsubst  %, source/%.c, $(PRINTF_FUNC))
PRINTF_OBJ   =  $(patsubst %, %.o , $(PRINTF_FUNC))

SRC = $(LIB_SRC) $(PRINTF_SRC)
OBJ = $(LIB_OBJ) $(PRINTF_OBJ)


%.o: libft/%.c
	gcc $(FLAGS) -c -I $(HEADER) -I libft/ $< -o $@
	ar rc $(NAME) $@
	
%.o: source/%.c  ft_printf.h
	gcc $(FLAGS) -c -I $(HEADER) -I libft/ $< -o $@
	ar rc $(NAME) $@
	
all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re
