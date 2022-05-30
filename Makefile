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

NAME_BONUS = checker

PRINTF = ./printf/libftprintf.a

SRCS = final_sort.c Libft_Utils_lst.c Libft_Util.c cost_methods.c execution_functions.c ft_split.c Parsing.c ft_atoi_ps.c push_swap.c helper_functions.c Instructions_partI.c sorting_partI.c Instructions_partII.c sorting_partII.c
SRCS_BONUS = get_next_line.c Libft_Util.c checker.c get_next_line_utils.c Libft_Utils_lst.c helper_functions.c Parsing.c ft_atoi_ps.c ft_split.c Instructions_partI.c Instructions_partII.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

FLAGS = -g3 -Wall -Wextra -Werror

all:: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./printf
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(PRINTF)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C ./printf
	gcc $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(PRINTF)

$(OBJS_BONUS): $(SRCS_BONUS)
	gcc $(FLAGS) -c $(SRCS_BONUS)

bonus: $(NAME_BONUS)

clean:
	rm -f *.o
	$(MAKE) clean -C ./printf

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
