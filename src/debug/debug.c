/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:34:44 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/24 18:57:45 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_env *env)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_data	*data;

	lst_a = *env->begin_a;
	lst_b = *env->begin_b;
	ft_printf("Stack A:\n");
	while (lst_a)
	{
		data = lst_a->content;
		ft_printf("\t%d\n", (int)data->value);
		lst_a = lst_a->next;
	}
	ft_printf("-----------\n");
	ft_printf("Stack B:\n");
	while (lst_b)
	{
		data = lst_b->content;
		ft_printf("\t%d\n", (int)data->value);
		lst_b = lst_b->next;
	}
	ft_printf("-----------\n");
	ft_printf("SIZE: %d\n", env->size_a);
}

void	test_operations(t_env *env)
{
	ft_printf("TEST\n");
	push_swap(env);
	print_stacks(env);
}
