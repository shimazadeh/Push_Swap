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
#include <stdio.h>
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	length;
    int     result;

	length = 0;
	if (s)
		length = ft_strlen(s);
	if (length < len)
		dst = (char *) malloc (sizeof(char) * (length + 1));
	else
		dst = (char *) malloc (sizeof(char) * (len + 1));
	if (s == NULL || dst == NULL)
		return (0);
	i = 0;
	j = start;
	while (i < len && j < ft_strlen(s))
		dst[i++] = s[j++];
	dst[i] = '\0';
    result = ft_atoi(dst);
    free(dst);
	return (result);
}

void    parsing(t_list *lst, char **arg) 
{
    int     i;
    int     j;
    int     start;
    int     buffer;
    t_list  *new_lst;

    i = 1;
    while (arg[i])
    {
        j = 0;
        while (arg[i][j])
        {
            while (ft_isdigit(arg[i][j]) == 0)
                j++;
            start = j;
            while (!ft_isdigit(arg[i][j]))
                j++;
            buffer = ft_substr(arg[i], start, j);
            new_lst = ft_lstnew(buffer);
            ft_lstadd_back(lst, new_lst);
        }
        i++;
    }
    return ;
}


int main(int argc, char **argv)
{
    t_list *lst;
    int i;

    if (argc == 1)
        return (0);
    lst = (t_list *)malloc(sizeof(t_list));
    parsing(lst, argv);

    printf("the element of the list\n");   
    while (lst)
    {
        printf("%ls\n", lst->content);
        lst = lst->next;
    }
    return (0);
}