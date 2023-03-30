/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:33 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/30 16:12:05 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_rotations(t_env *env, int index, int n_index, int lim)
{
	int				diff;
	t_rotation_data	*rot;

	rot = env->rotation_data;
	diff = index - n_index;
	if (diff < 0 && (absolute(diff) <= lim))
	{
		rot->reps = n_index - index;
		rot->rev = 0;
	}
	else if (diff < 0 && (absolute(diff) > lim))
	{
		rot->reps = ((env->size_a) - n_index) + index;
		rot->rev = 1;
	}
	else if (diff > 0 && (absolute(diff) <= lim))
	{
		rot->reps = index - n_index;
		rot->rev = 1;
	}
	else if (diff > 0 && (absolute(diff) > lim))
	{
		rot->reps = ((env->size_a) - index) + n_index;
		rot->rev = 0;
	}
}

static void	rotate(t_env *env)
{
	int		lim;
	t_data	*data;
	t_list	*current;
	int		i;

	lim = env->size_a / 2;
	current = *env->begin_a;
	data = current->content;
	calculate_rotations(env, data->index, lowest_index(env), lim);
	i = 0;
	while (i < env->rotation_data->reps && !is_sorted(env))
	{
		if (env->rotation_data->rev == 1)
			rra(env);
		else
			ra(env);
		i++;
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
		env->highest = find_highest(env);
		while (env->algo_data->current && !is_sorted(env))
		{
			env->algo_data->data = env->algo_data->current->content;
			if (env->algo_data->data->value == env->lowest)
			{
				pb(env);
				break ;
			}
			rotate(env);
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
	env->highest = find_highest(env);
	if ((env->size_a == 0 || env->size_a == 1) || is_sorted(env))
		return ;
	if (env->size_a == 2)
		sort_2(env);
	else if (env->size_a == 3)
		sort_3(env);
	else
		sort_small(env);
}
