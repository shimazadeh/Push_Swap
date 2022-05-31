/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:14:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/28 01:14:53 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int c)
{
	if (ft_isdigit(c) || ft_issign(c))
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == 43 || c == 45)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		if (s1[k] == '\0')
			return (0);
		k++;
	}
	return (0);
}
