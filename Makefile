# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shabibol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 17:54:10 by shabibol          #+#    #+#              #
#    Updated: 2022/03/07 21:45:26 by shabibol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTF = ./printf/libftprintf.a

SRCS = final_sort.c Libft_Utils_lst.c Libft_Util.c cost_methods.c execution_functions.c ft_split.c Parsing.c ft_atoi_ps.c push_swap.c helper_functions.c Instructions_partI.c sorting_partI.c Instructions_partII.c sorting_partII.c
OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
all:: $(NAME)


$(NAME): $(OBJS)
	$(MAKE) -C ./printf
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(PRINTF)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	rm -f *.o
	$(MAKE) clean -C ./printf

fclean: clean
	rm -f $(NAME)

re: fclean all


# NAME = push_swap

# SRCS = ft_lstnew.c Libft_Util.c cost_methods.c ft_lstsize.c execution_functions.c ft_split.c Parsing.c ft_atoi.c ft_strncmp.c push_swap.c ft_lstadd_back.c helper_functions.c ft_lstadd_front.c Instructions_partI.c sorting_partI.c ft_lstlast.c Instructions_partII.c sorting_partII.c
# OBJS = ${SRCS:.c=.o}
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -rf

# all:: ${NAME}

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	${RM} ${OBJS}

# fclean: clean
# 	${RM} $(NAME)

# re: fclean all
