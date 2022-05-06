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

void    parsing(t_list **lst, char **arg) 
{
    int     i;
    int     j;
    int     start;
    int     buffer;
    int     size;
    t_list  *new_lst;

    i = 1;
    while (arg[i])
    {
        size = ft_strlen(arg[i]);
        j = 0;
        while (arg[i][j] && j < size)
        {
            while (j < size && !ft_isnum(arg[i][j]))
                j++;
            start = j;
            while (j < size && ft_isnum(arg[i][j]) == 1)
                j++;
            if (j <= size)
            {
                buffer = ft_substr(arg[i], start, j);
                new_lst = ft_lstnew(buffer);
                ft_lstadd_back(lst, new_lst);
            }
            j++;
        }
        i++;
    }
    return ;
}




int allowed_char_check(char **arg) //accept only digits/signs/space
{
    int i;
    int j;
    int size;

    i = 1;
    while (arg[i])
    {
        size = ft_strlen(arg[i]);
        j = 0;
        while (arg[i][j] && j < size)
        {
            if (!ft_isnum(arg[i][j]) && !ft_isspace(arg[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int dup_error_check(char **arg) //checks for duplicates
{
    int     j;
    int     k;
    int     size;

    j = 0;
    while (arg[j])
    {
        k = j + 1;
        if (!ft_strcmp(arg[j], "2147483647"))
            return (1);
        if (!ft_strcmp(arg[j], "-2147483648"))
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

int multi_check(char *arg)
{
    char    **tab;
    
    tab = ft_split(arg, ' ');
    if (dup_error_check (tab) == 1)
    {
        free(tab);
        return (1);
    }
    free(tab);
    return (0);
}

int all_error_checks(int size, char **arg)
{
    if (size == 1)
        return (2);
    if (allowed_char_check(arg) == 1)
        return (1);
    if (size > 2 && dup_error_check(arg) == 1)
        return (1);
    if (size == 2 && multi_check(arg[1]) == 1)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    t_list *lst;

    if (all_error_checks(argc, argv) == 1)
        {
            write(1, "Error\n", 6);
            return (0);
        }
    else if (all_error_checks(argc, argv) == 2)
        return (0);
    lst = NULL;
    parsing(&lst, argv);
    printf("the element of the list\n");   
    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
    return (0);
}