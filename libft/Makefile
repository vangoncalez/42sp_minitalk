# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 14:13:56 by vaferrei          #+#    #+#              #
#    Updated: 2021/12/22 15:42:43 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_numberlen.c \
			ft_hexlen.c \
			get_next_line.c \
			ft_atoi_base.c \
			ft_printf.c \
			ft_make_char.c \
			ft_make_decimal.c \
			ft_make_undecimal.c \
			ft_make_hexa.c \
			ft_make_pointer.c \
			ft_treat_char.c \
			ft_treat_decimal.c \
			ft_treat_undecimal.c \
			ft_treat_hexa.c \
			ft_treat_pointer.c \
			ft_treat_flags.c \
			ft_lstnew.c\
       		ft_lstadd_front.c\
       		ft_lstsize.c\
       		ft_lstlast.c\
       		ft_lstadd_back.c\
       		ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re
