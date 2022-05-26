/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:49:59 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/24 15:50:03 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	display(t_stack *b)
{
	while (b)
	{
		printf("the content is: %d\n", b->content);
		/*
		printf("the cost1 is: %d\n", b->cost1);
		printf("the cost2 is: %d\n", b->cost2);
		printf("the cost3 is: %d\n", b->cost3);
		printf("the cost4 is: %d\n", b->cost4);*/
		printf("\n");
		b = b->next;
	}
}

int	check_limits(t_stack **head_a)
{
	t_stack *a;
	int     min;
	int     max;

	min = -2147483648;
	max = 2147483647;
	a = *head_a;
	while (a)
	{
		if (a->content > max || a->content < min)
			return (1);
		a = a->next;
	}
	return (0);
}
/*
void	manual_sort(t_stack **head_a, t_struct *tab)
{
	t_stack *a;
	t_stack *last;

	a = head_a;
	last = ft_lstlast(*a);
	if (ft_lstsize(a) == 2)
	{
		if (a->content > a->next->content)
			rotate(head_a, "ra");
	}
	else if (ft_lstsize(a) == 3)
		initial_sort_stack_a(head_a);
	else if (ft_lstsize(a) == 4)
	{
		if (a->content == tab->max)
			rotate(&a);

	}
	return ;
}*/

int	main(int argc, char **argv)
{
	t_stack     *a;
	t_struct    *tab;
	t_stack     *b;
	t_ind       *index;

	a = (t_stack *)malloc(sizeof(t_struct));
	b = (t_stack *)malloc(sizeof(t_struct));
	tab = (t_struct *)malloc(sizeof(t_struct));
	index = (t_ind *)malloc(sizeof(t_ind));
	a = NULL;
	b = NULL;
	if (all_error_checks(argc, argv) == 1)
			return (0);
	parsing(&a, argv);
	if (sort_check(&a) == 0 || argc == 1)
		return (0);
	update_tab(tab, &a);
	move_to_stack_b(&a, &b, tab);
	execution_function(&a, &b, index);
	final_check(&a, tab);
/*
	printf("the stack a after execution:\n");
	display(a);
	printf("the stack b after execution:\n");
	display(b);
*/
	ft_free_lst(&a);
	ft_free_lst(&b);
	free(tab);
	free(index);
	return (0);
}

