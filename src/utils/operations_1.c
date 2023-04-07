/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:55:12 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/24 17:30:43 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	t_list	*first;
	t_list	*tmp;

	first = *env->begin_a;
	tmp = first->next;
	first->next = tmp->next;
	ft_lstadd_front(env->begin_a, tmp);
	update_index(env);
}

void	sb(t_env *env)
{
	t_list	*first;
	t_list	*tmp;

	first = *env->begin_b;
	tmp = first->next;
	first->next = tmp->next;
	ft_lstadd_front(env->begin_b, tmp);
	update_index(env);
}

void	ss(t_env *env)
{
	sa(env);
	sb(env);
}

void	pa(t_env *env)
{
	t_list	*first;
	t_list	*tmp;

	first = *env->begin_b;
	if (first)
	{
		tmp = first->next;
		*env->begin_b = tmp;
	}
	ft_lstadd_front(env->begin_a, first);
	update_index(env);
}

void	pb(t_env *env)
{
	t_list	*first;
	t_list	*tmp;

	first = *env->begin_a;
	if (first)
	{
		tmp = first->next;
		*env->begin_a = tmp;
	}
	ft_lstadd_front(env->begin_b, first);
	update_index(env);
}
