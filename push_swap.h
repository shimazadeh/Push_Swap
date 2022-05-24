/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:53:58 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/05 06:54:50 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
//# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				cost1;
	int				cost2;
	int				cost3;
	int				cost4;
	struct s_stack	*next;
	struct s_stack	*previous;
}t_stack;

typedef struct s_struct
{
	int				min;
	int				max;
	int 			median;
}t_struct;

typedef struct s_ind
{
	int				lowest_cost;
	int 			method_num;
	int				index_a;
	int 			index_b;
}t_ind;

//libft functions
int					ft_isdigit(int c);
long long int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_issign(int c);
int					ft_isspace(int c);
int					ft_isnum(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);

//helpers
int 				ft_max(int a, int b);
int 				ft_min(int a, int b);
int 				ft_abs_value(int a, int b);
int					ft_strlen_tab(char **tab);
int					ft_strcmp(const char *s1, const char *s2);


char				**ft_free(char **dst, int i);
void    			ft_free_lst(t_stack **lst);

//parsing functions
int 				all_error_checks(int size, char **arg);
int					allowed_char_check(char **arg);
int					dup_error_check(char **arg);
int 				multi_check(char *arg);
void				parsing(t_stack **lst, char **arg);
int 				sort_check(t_stack **head_a);
int					check_limits(t_stack **head_a);

//instructions
void    			swap(t_stack **lst, char *str);
void    			push(t_stack **head_to, t_stack **head_from, char *str);
void    			rotate(t_stack **head_lst, char *str);
void    			reverse_rotate(t_stack **head_lst, char *str);
void    			swap_both_lst(t_stack **a, t_stack **b);
void    			rotate_both_lst(t_stack **a, t_stack **b);
void    			rev_rotate_both_lst(t_stack **a, t_stack **b);

//sorting algorithm
void    			find_median(t_stack **head_lst, t_struct *tab);
void    			find_min_max(t_stack **head_lst, t_struct *tab);
t_struct			*initialize_tab(t_struct  *tab);

//one function to move everything else to stack B
void				move_to_stack_b(t_stack **head_a, t_stack **head_b, t_struct *tab);
void    			initial_sort_stack_a(t_stack **head_a, t_struct *tab);

//four methods combinations
int 				calculate_cost_method1(int index_a, int index_b);
int 				calculate_cost_method2(int index_a, int index_b, t_stack **head_a, t_stack **head_b);
int 				calculate_cost_method3(int index_a, int index_b, t_stack **head_b);
int 				calculate_cost_method4(int index_a, int index_b, t_stack **head_a);

//calculating the cost of each element of the list
void    			calculate_all_costs(t_stack **head_a, t_stack **head_b, t_ind *index);
void    			update_lowest_cost(t_stack *head_b, t_ind *index, int index_a, int index_b);
void    			initialize_costs_index(t_stack **head_b, t_ind *index);

//function to execute the method
void				execution_function(t_stack **head_a, t_stack **head_b, t_ind *index);
void				execute_method1(t_ind *index, t_stack **head_a, t_stack **head_b);
void				execute_method2(t_ind *index, t_stack **head_a, t_stack **head_b);
void				execute_method3(t_ind *index, t_stack **head_a, t_stack **head_b);
void				execute_method4(t_ind *index, t_stack **head_a, t_stack **head_b);


void				final_check(t_stack **head_a, t_struct *tab);
void				final_sort_odd(t_stack **head_a, int position, int len);
void				final_sort_even(t_stack **head_a, int position, int len);

//lst functions
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);


//not sure if I need it

void    			display(t_stack *b);

#endif
