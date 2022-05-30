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
//	else if (ft_strlen(res) > 1)
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			fd;
	char		*res;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a = NULL;
	b = NULL;
	if (all_error_checks(argc, argv) == 1)
		return (0);
	parsing(&a, argv);
	if (argc == 1)
		return (0);
	fd = 0;
	while ((res = get_next_line(fd)))
	{
		if (checker(res, &a, &b) == 1)
		{
			free(res);
			return (0);
		}
		free(res);
	}
	if (b || sort_check(&a) == 1)
		write(1, "KO\n",3);
	else
		write(1, "OK\n", 3);
	/*
	printf("the content of stack a after sorting:\n");
	display(a);
	printf("the content of stack b after sorting:\n");
	display(b);
*/
	ft_free_lst(&a);
	ft_free_lst(&b);
	return (0);
}
