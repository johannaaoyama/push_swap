/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:23:04 by jaoyama           #+#    #+#             */
/*   Updated: 2026/09/01 15:29:01 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(t_stack *a)
{

        // 1. If no parameters are specified, the program must not display anything and give the prompt back.
        // 2. check if list_a is valid -> proceed with function below; else return (1);
        validate_a(a); // proceed or return "Error \n"

        // 3. if algo not specified, go adaptive -> decide based on disorder
        {
                disorder = calc_disorder(a);
                if (--simple == true || (disorder < 0.2 && --medium == false && --complex == false))
                        simple(a);
                        // return: ft_printf(ops) and send benchmarks to stderr; or Error
                        // benchmarks to stderr
                        int i = 0;
                        while (i <= 4)
                                write(2, arr[i], ft_strlen(arr[i]));
                                write(2, "\n", 1);

                        // benchmark output array
                        a = ft_printf("Disorder: %d", disorder);
                        "name" "complexity class"
                        total # of ops: ops_count(a)
                        operation types count: type_count(a)

                        // if (--bench == true)
                                ft_printf(stderr);
                if (––medium == true || (disorder < 0.5 && disorder >= 0.2))
                        medium(a);
                if (--complex == true || disorder >= 0.5)
                        complex(a);
        }

void    simple(a)
{
        // print the ops separated by \n, use write or rather ft_printf here?
        write(1, ops, sizeof(ops));
}
