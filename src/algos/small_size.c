/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:33 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/05 14:43:11 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_rotations(t_env *env, int index, int lim, char lst)
{
	t_rotation_data	*rot;

	rot = env->rotation_data;
	if (index <= lim)
	{
		rot->reps = index;
		rot->rev = 0;
	}
	else
	{
		if (lst == 'a')
			rot->reps = env->size_a - index;
		else
			rot->reps = env->size_b - index;
		rot->rev = 1;
	}
}

void	rotate(t_env *env, char lst)
{
	int	i;

	if (lst == 'a')
		env->algo_data->lim = env->size_a / 2;
	else
		env->algo_data->lim = env->size_b / 2;
	calculate_rotations(env, lowest_index(env), env->algo_data->lim, lst);
	i = 0;
	while (i++ < env->rotation_data->reps)
	{
		if (env->rotation_data->rev == 1)
		{
			if (lst == 'a')
				rra(env);
			else
				rrb(env);
		}
		else
		{
			if (lst == 'a')
				ra(env);
			else
				rb(env);
		}
	}
}

static void	sort_small(t_env *env)
{
	env->algo_data->current = *env->begin_a;
	if (ft_lstsize(env->algo_data->current) == 3)
		sort_3(env);
	else if (is_sorted(env))
		return ;
	else
	{
		env->lowest = find_lowest(env);
		env->highest = find_highest(env, 'a');
		while (env->algo_data->current && !is_sorted(env))
		{
			env->algo_data->data = env->algo_data->current->content;
			if (env->algo_data->data->value == env->lowest)
			{
				pb(env);
				break ;
			}
			rotate(env, 'a');
			env->algo_data->current = *env->begin_a;
		}
		if (!is_sorted(env))
			sort_small(env);
		if (env->size_b != 0)
			pa(env);
	}
}

void	small_size(t_env *env)
{
	env->lowest = find_lowest(env);
	env->highest = find_highest(env, 'a');
	bubble_sort(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	if (env->size_a == 2)
		sort_2(env);
	else if (env->size_a == 3)
		sort_3(env);
	else
		sort_small(env);
}
