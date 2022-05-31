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

int	find_sec_min(t_stack **head_lst, t_struct *tab)
{
	t_stack	*stack;
	int		temp;

	stack = *head_lst;
	while (stack)
	{
		temp = stack->content;
		if (tab->min < temp && tab->median > temp)
			return (temp);
		stack = stack->next;
	}
	return (0);
}

void	push_swap_low_stack(t_stack **a, t_stack **b, t_struct *tab)
{
	int		min_sec;

	update_tab(tab, a);
	min_sec = find_sec_min(a, tab);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content == tab->min || (*a)->content == min_sec)
			push(b, a, "pb");
		else
			rotate(a, "ra");
	}
	update_tab(tab, a);
	initial_sort_stack_a(a, tab);
	while (*b)
	{
		if ((*b)->next && (*b)->content < (*b)->next->content)
			reverse_rotate(b, "rrb");
		push(a, b, "pa");
	}
	return ;
}

void	push_swap(t_stack **a, t_stack **b, t_struct *tab, t_ind *index)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			rotate(a, "ra");
	}
	else if (ft_lstsize(*a) == 3)
	{
		update_tab(tab, a);
		initial_sort_stack_a(a, tab);
	}
	else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
		push_swap_low_stack(a, b, tab);
	else
	{
		update_tab(tab, a);
		move_to_stack_b(a, b, tab);
		execution_function(a, b, index);
		final_check(a, tab);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_struct	*tab;
	t_stack		*b;
	t_ind		*index;

	tab = (t_struct *)malloc(sizeof(t_struct));
	index = (t_ind *)malloc(sizeof(t_ind));
	a = NULL;
	b = NULL;
	if (all_error_checks(argc, argv) == 1)
		return (free(tab), free(index), 0);
	parsing(&a, argv);
	if (sort_check(&a) == 0 || argc == 1)
		return (ft_free_lst(&a), free(tab), free(index), 0);
	push_swap(&a, &b, tab, index);
	ft_free_lst(&a);
	free(tab);
	free(index);
	return (0);
}
