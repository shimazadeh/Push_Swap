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

PRINTF = $(addprefix printf/, ft_base_function.c ft_base_function_partII.c ft_paddings.c ft_parsing.c ft_print_subs.c ft_print_subs_partII.c ft_printf.c ft_put.c ft_eval_flags.c ft_eval_flags_int.c)
SRCS = ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_split.c ft_strncmp.c cost_methods.c execution_functions.c helper_functions.c Instructions_partI.c Instructions_partII.c Libft_Util.c Parsing.c push_swap.c sorting_partI.c sorting_partII.c

OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

all:: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
