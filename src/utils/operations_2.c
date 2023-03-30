/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:39 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/24 17:31:01 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_env *env)
{
	t_list	*first;

	first = *env->begin_a;
	*env->begin_a = first->next;
	first->next = NULL;
	ft_lstadd_back(env->begin_a, first);
	update_index(env);
	ft_printf("ra\n");
}

void	rb(t_env *env)
{
	t_list	*first;

	first = *env->begin_b;
	*env->begin_b = first->next;
	first->next = NULL;
	ft_lstadd_back(env->begin_b, first);
	update_index(env);
	ft_printf("rb\n");
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
	ft_printf("rr\n");
}

void	rra(t_env *env)
{
	t_list	*last;
	t_list	*begin;
	t_list	*current;

	begin = *env->begin_a;
	current = begin;
	last = ft_lstlast(begin);
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstadd_front(env->begin_a, last);
	*env->begin_a = last;
	update_index(env);
	ft_printf("rra\n");
}

void	rrb(t_env *env)
{
	t_list	*last;
	t_list	*begin;
	t_list	*current;

	begin = *env->begin_b;
	current = begin;
	last = ft_lstlast(begin);
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	ft_lstadd_front(env->begin_b, last);
	*env->begin_b = last;
	update_index(env);
	ft_printf("rrb\n");
}
