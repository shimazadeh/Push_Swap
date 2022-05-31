/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:18:17 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/08 18:18:20 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_stack **lst, char **arg)
{
	int			i;
	int			j;
	char		**tab;
	int			buffer;
	t_stack		*new_lst;

	i = 1;
	while (arg[i])
	{
		tab = ft_split(arg[i], ' ');
		j = 0;
		while (tab[j])
		{
			buffer = ft_atoi_ps(tab[j]);
			new_lst = ft_lstnew(buffer);
			ft_lstadd_back(lst, new_lst);
			j++;
		}
		i++;
		ft_free(tab, j);
	}
	return ;
}

int	allowed_char_check(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j] && j < ft_strlen(arg[i]))
		{
			if (!ft_isnum(arg[i][j]) && !ft_isspace(arg[i][j]))
				return (1);
			if (ft_issign(arg[i][j]) == 1)
			{
				if (ft_strlen(arg[i]) == 1 || ft_issign(arg[i][j + 1]) == 1)
					return (1);
				if (ft_isdigit(arg[i][j + 1]) == 0)
					return (1);
				if (arg[i][j - 1] && ft_isdigit(arg[i][j - 1]) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	dup_error_check(char **arg)
{
	int	j;
	int	k;
	int	size;

	j = 0;
	while (arg[j])
	{
		k = j + 1;
		if (ft_atoi_ps(arg[j]) > 2147483647 || ft_atoi_ps(arg[j]) < -2147483648)
			return (1);
		while (arg[k])
		{
			size = ft_max(ft_strlen(arg[j]), ft_strlen(arg[k]));
			if (!ft_strncmp(arg[j], arg[k], size))
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

int	multi_check(char *arg)
{
	char	**tab;
	int		size;

	tab = ft_split(arg, ' ');
	size = ft_strlen_tab(tab);
	if (dup_error_check (tab) == 1)
		return (ft_free(tab, size), 1);
	return (ft_free(tab, size), 0);
}

int	all_error_checks(int size, char **arg)
{
	if (size == 1)
		return (2);
	if (allowed_char_check(arg) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (size > 2 && dup_error_check(arg) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (size == 2 && multi_check(arg[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
