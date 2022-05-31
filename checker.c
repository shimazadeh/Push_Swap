/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:16:34 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/31 15:16:36 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack **head_a)
{
	t_stack	*a;
	t_stack	*a_iteri;

	a = *head_a;
	while (a)
	{
		a_iteri = a->next;
		while (a_iteri)
		{
			if (a->content > a_iteri->content)
				return (1);
			a_iteri = a_iteri->next;
		}
		a = a->next;
	}
	return (0);
}

int	checker(char *res, t_stack **head_a, t_stack **head_b)
{
	if (ft_strncmp(res, "pb\n", 3) == 0)
		push(head_b, head_a, "");
	else if (ft_strncmp(res, "pa\n", 3) == 0)
		push(head_a, head_b, "");
	else if (ft_strncmp(res, "rr\n", 3) == 0)
		rotate_both_lst(head_a, head_b, "");
	else if (ft_strncmp(res, "rrr\n", 3) == 0)
		rev_rotate_both_lst(head_a, head_b, "");
	else if (ft_strncmp(res, "ra\n", 3) == 0)
		rotate(head_a, "");
	else if (ft_strncmp(res, "rra\n", 3) == 0)
		reverse_rotate(head_a, "");
	else if (ft_strncmp(res, "rb\n", 3) == 0)
		rotate(head_b, "");
	else if (ft_strncmp(res, "rrb\n", 3) == 0)
		reverse_rotate(head_b, "");
	else if (ft_strncmp(res, "sa\n", 3) == 0)
		swap(head_a, "");
	else if (ft_strncmp(res, "sb\n", 3) == 0)
		swap(head_b, "");
	else
		return (1);
	return (0);
}

void	result_check(t_stack **head_a, t_stack **head_b)
{
	if (*head_b || sort_check(head_a) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*res;

	a = NULL;
	b = NULL;
	if (all_error_checks(argc, argv) == 1 || argc == 1)
		return (0);
	parsing(&a, argv);
	if (sort_check(&a) == 0)
		return (ft_free_lst(&a), 0);
	res = get_next_line(0);
	while (res)
	{
		if (checker(res, &a, &b) == 1)
		{
			write(1, "Error\n", 6);
			return (free(res), ft_free_lst(&a), ft_free_lst(&b), 0);
		}
		free(res);
		res = get_next_line(0);
	}
	result_check(&a, &b);
	return (ft_free_lst(&a), ft_free_lst(&b), 0);
}
