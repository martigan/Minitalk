#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 16:23:58 by mgaspail          #+#    #+#              #
#    Updated: 2014/02/08 20:40:12 by mgaspail         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = serveur

NAME2 = client

SRC1_C = server.c server2.c tools.c tools2.c

SRC2_C = client.c tools.c

SRC1_O = $(SRC1_C:.c=.o)

SRC2_O = $(SRC2_C:.c=.o)

FLAG = -Wall -Werror -Wextra -g

all			: $(NAME) $(NAME2)

$(NAME)		: $(SRC1_O)
			gcc $(FLAG) -o $(NAME) $^

$(NAME2)	: $(SRC2_O)
			gcc $(FLAG) -o $(NAME2) $^

%.o			: %.c
			gcc $(FLAG) -c $<

clean		:
			rm -f $(SRC1_O) $(SRC2_O)

fclean		: clean
			rm -f $(NAME) $(NAME2)

re			: fclean all
