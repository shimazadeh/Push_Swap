/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:11:37 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/10 15:11:39 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*update_tab(t_struct *tab, t_stack **head_lst)
{
	tab->min = -1;
	tab->max = -1;
	tab->median = -1;
	if (ft_lstsize(*head_lst) > 2)
	{
		find_min_max(head_lst, tab);
		find_median(head_lst, tab);
	}
	return (tab);
}

void	find_min_max(t_stack **head_lst, t_struct *tab)
{
	int		temp;
	t_stack	*stack;

	stack = *head_lst;
	tab->min = stack->content;
	tab->max = stack->content;
	while (stack)
	{
		temp = stack->content;
		if (tab->min > temp)
			tab->min = temp;
		if (tab->max < temp)
			tab->max = temp;
		stack = stack->next;
	}
	return ;
}

void	find_median(t_stack **head_lst, t_struct *tab)
{
	t_stack	*start;
	t_stack	*compare;
	int		size;
	int		count;

	start = *head_lst;
	size = ft_lstsize(start);
	while (start)
	{
		count = 0;
		compare = *head_lst;
		while (compare)
		{
			if (start->content < compare->content)
				count++;
			compare = compare->next;
		}
		if (count == size / 2)
		{
			tab->median = start->content;
			return ;
		}
		start = start->next;
	}
}

void	move_to_stack_b(t_stack **head_a, t_stack **head_b, t_struct *tab)
{
	t_stack	**a;
	t_stack	**b;
	int		size;

	a = head_a;
	b = head_b;
	size = ft_lstsize(*a);
	while (size > 0)
	{
		if ((*a)->content == tab->min)
			rotate(a, "ra");
		else if ((*a)->content == tab->max)
			rotate(a, "ra");
		else if ((*a)->content == tab->median)
			rotate(a, "ra");
		else
			push(b, a, "pb");
		size--;
	}
	initial_sort_stack_a(head_a, tab);
	return ;
}

void	initial_sort_stack_a(t_stack **head_a, t_struct *tab)
{
	t_stack	**a;

	a = head_a;
	if ((*a)->content == tab->max && (*a)->next->content == tab->min)
		rotate(a, "ra");
	else if ((*a)->content == tab->max && (*a)->next->content == tab->median)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if ((*a)->content == tab->median && (*a)->next->content == tab->min)
		swap(a, "sa");
	else if ((*a)->content == tab->median && (*a)->next->content == tab->max)
		reverse_rotate(a, "rra");
	else if ((*a)->content == tab->min && (*a)->next->content == tab->max)
	{
		rotate(a, "ra");
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	return ;
}
