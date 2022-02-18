# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 15:15:06 by nahaddac          #+#    #+#              #
#    Updated: 2022/02/18 23:11:00 by nahaddac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c utils.c ft_split.c ft_atoi.c swap.c \
					init_stack.c sort.c ft_quick_sort.c \
					ft_radix_sort.c push_stack.c swap_rotate.c \
					swap_ss.c init_stack_two.c utils_2.c \
					utils_3.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
SEGV			= -g #-fsanitize=address
CFLAGS			= $(SEGV) -Wall -Wextra -Werror

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re