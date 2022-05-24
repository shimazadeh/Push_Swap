/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_partI.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:28:27 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/12 19:28:29 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position_conditionI(t_stack *head_a, t_stack *head_b)
{
	int i;

	i = 0;
	while (head_a->next && head_a->content < head_a->next->content)
	{
		head_a = head_a->next;
		i++;
	}
	if (head_a->next)
	{
		head_a = head_a->next;
		i++;
		while (head_a && head_b->content > head_a->content)
		{
			head_a = head_a->next;
			i++;
		}
		if (!head_a)
			i = 0;
	}
	else if (!head_a->next && head_b->content < head_a->content)
		i = 0;
	return (i);
}

int	calculate_position_conditionII(t_stack *head_a, t_stack *head_b)
{
	int i;

	i = 0;
	while (head_a->next && head_b->content > head_a->content && head_a->content < head_a->next->content)
	{
		head_a = head_a->next;
		i++;
	}
	if (!head_a->next && head_b->content > head_a->content)
	i = 0;
	return (i);
}

void	calculate_all_costs(t_stack **head_a, t_stack **head_b, t_ind *index)
{
	int			i;
	int			j;
	t_stack		*b;
	t_stack		*a;

	j = 0;
	b = *head_b;
	while (b)
	{
		i = 0;
		a = *head_a;
		if (b->content < a->content)
			i = calculate_position_conditionI(a, b);
		else if (b->content > a->content)
			i = calculate_position_conditionII(a, b);
		b->cost1 = calculate_cost_method1(i, j);
		b->cost2 = calculate_cost_method2(i, j, head_a, head_b);
		b->cost3 = calculate_cost_method3(i, j, head_b);
		b->cost4 = calculate_cost_method4(i, j, head_a);
		update_lowest_cost(b, index, i, j);
		j++;
		b = b->next;
	}
	return ;
}

void	update_lowest_cost(t_stack *head_b, t_ind *index, int index_a, int index_b)
{
	if (head_b->cost1 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost1;
		index->method_num = 1;
		index->index_b = index_b;
		index->index_a = index_a;
	}
	if (head_b->cost2 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost2;
		index->method_num = 2;
		index->index_b = index_b;
		index->index_a = index_a;
	}
	if (head_b->cost3 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost3;
		index->method_num = 3;
		index->index_b = index_b;
		index->index_a = index_a;
	}
	if (head_b->cost4 < index->lowest_cost)
	{
		index->lowest_cost = head_b->cost4;
		index->method_num = 4;
		index->index_b = index_b;
		index->index_a = index_a;
	}
	return ;
}

void	initialize_costs_index(t_stack **head_b, t_ind *index)
{
	t_stack	*b;

	b = *head_b;
	while (b)
	{
		b->cost1 = -1;
		b->cost2 = -1;
		b->cost3 = -1;
		b->cost4 = -1;
		b = b->next;
	}
	index->lowest_cost = 2147483647;
	index->method_num = -1;
	index->index_a = -1;
	index->index_b = -1;
	return ;
}

void	final_sort_odd(t_stack **head_a, int position, int len)
{
	int	count;

	count = 0;
	if (position > len / 2)
	{
		while (count != (len - position))
		{
			reverse_rotate(head_a, "rra");
			count++;
		}
	}
	else
	{
		while (count != position)
		{
			rotate(head_a, "ra");
			count++;
		}
	}
	return ;
}

void	final_sort_even(t_stack **head_a, int position, int len)
{
	int	count;

	count = 0;
	if (position >= len / 2)//min is closer to the end of the stack
	{
		while (count != (len - position))
		{
			count++;
			reverse_rotate(head_a, "rra");
		}
	}
	else //min is closer to the top of the stack
	{
		while (count != position)
		{
			rotate(head_a, "ra");
			count++;
		}
	}
	return ;
}

void	final_check(t_stack **head_a, t_struct *tab)
{
	t_stack	*a;
	int		position;
	int		len;

	a = *head_a;
	position = 0;
	len = ft_lstsize(*head_a);
	if ((a)->content != tab->min)
	{
		while ((a) && (a)->content != tab->min)
		{
			position++;
			(a) = (a)->next;
		}
		if (len % 2 != 0) //length is odd
			final_sort_odd(head_a, position, len);
		else //length is even
			final_sort_even(head_a, position, len);
	}
	return ;
}

/*
void	final_check(t_stack **head_a, t_struct *tab)
{
	t_stack	*a;
	int		position;
	int		len;
	int		count;

	a = *head_a;
	position = 0;
	len = ft_lstsize(*head_a);
	count = 0;
	if ((a)->content != tab->min)
	{
		while ((a) && (a)->content != tab->min)
		{
			position++;
			(a) = (a)->next;
		}
		if (len % 2 != 0) //length is odd
		{
			if (position > len / 2)//min is closer to the end of the stack
			{
				while (count != (len - position))
				{
					reverse_rotate(head_a, "rra");
					count++;
				}
			}
			else //min is closer to the top of the stack
			{
				while (count != position)
				{
					rotate(head_a, "ra");
					count++;
				}
			}
		}
		else //length is even
		{
			if (position >= len / 2)//min is closer to the end of the stack
			{
				while (count != (len - position))
				{
					count++;
					reverse_rotate(head_a, "rra");
				}
			}
			else //min is closer to the top of the stack
			{
				while (count != position)
				{
					rotate(head_a, "ra");
					count++;
				}
			}
		}
	}
	return ;
}
*/
/*
void	calculate_all_costs(t_stack **head_a, t_stack **head_b, t_ind *index)
{
	int			i;
	int			j;
	t_stack		*b;
	t_stack		*a;

	j = 0;
	b = *head_b;
	while (b)
	{
		i = 0;
		a = *head_a;
		if (b->content < a->content)
		{
			while (a->next && a->content < a->next->content)
			{
				a = a->next;
				i++;
			}
			if (a->next)
			{
				a = a->next;
				i++;
				while (a && b->content > a->content)
				{
					a = a->next;
					i++;
				}
				if (!a)
					i = 0;
			}
			else if (!a->next && b->content < a->content)
				i = 0;
		}
		else if (b->content > a->content)
		{
			while (a->next && b->content > a->content && a->content < a->next->content)
			{
				a = a->next;
				i++;
			}
			if (!a->next && b->content > a->content)
				i = 0;
		}
		b->cost1 = calculate_cost_method1(i, j, head_a, head_b);
		b->cost2 = calculate_cost_method2(i, j, head_a, head_b);
		b->cost3 = calculate_cost_method3(i, j, head_a, head_b);
		b->cost4 = calculate_cost_method4(i, j, head_a, head_b);
		update_lowest_cost(b, index, i, j);
		j++;
		b = b->next;
	}
	return ;
}
*/
