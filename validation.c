/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:25:07 by kevin             #+#    #+#             */
/*   Updated: 2026/09/01 14:42:29 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int is_number(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int has_duplicates(t_stack *a)
{
    t_node *current_node;
    t_node *next_node;

    current_node = a->head;
    while(current_node)
    {
        next_node = current_node->next;
        while(next_node)
        {
            if (current_node->value == next_node->value)
                return (1);
            next_node = next_node->next;
        }
        current_node = current_node->next;
    }
    return (0);
}

int	is_valid_int(const char *str)
{
	long	num;

	if (!is_number(str))
		return (0);
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	parse_to_stack(int argc, char **argv, t_stack *a)
{
	int		i;
	long	num;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
        node = new_node((int)num);
        if (!node)
            return (0);
        append_node(a, node);
		i++;
	}
    if (has_duplicates(a))
        return (0);
	return (1);
}