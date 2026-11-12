/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:05:25 by kevin             #+#    #+#             */
/*   Updated: 2026/09/02 12:12:59 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_email@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02                              #+#    #+#             */
/*   Updated: 2026/09/02                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_token(char *start, int len, t_stack *a)
{
	long	num;
	t_node	*node;

	if (!is_valid_int_len(start, len))
		return (0);
	num = ft_atol_len(start, len);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	node = new_node((int)num);
	if (!node)
		return (0);
	append_node(a, node);
	return (1);
}

static int	parse_argument(char *arg, t_stack *a)
{
	int	i;
	int	start;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13)))
			i++;
		if (!arg[i])
			break ;
		start = i;
		while (arg[i] && arg[i] != ' ' && !(arg[i] >= 9 && arg[i] <= 13))
			i++;
		if (!add_token(&arg[start], i - start, a))
			return (0);
	}
	return (1);
}

static int	parse_arguments(int count, char **args, t_stack *a)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!args[i][0] || !parse_argument(args[i], a))
			return (0);
		i++;
	}
	return (1);
}

int	parse_and_validate(t_stack *a, int count, char **args)
{
	stack_init(a);
	if (!parse_arguments(count, args, a))
	{
		stack_clear(a);
		return (0);
	}
	if (has_duplicates(a))
	{
		stack_clear(a);
		return (0);
	}
	return (1);
}
