/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:34:10 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/06 20:00:58 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_variables_bubblesort(t_env *env, int j)
{
	int	tmp;

	env->algo_data->current = find_elem_nindex(env, j, 'a');
	env->algo_data->tmp = find_elem_nindex(env, j + 1, 'a');
	env->algo_data->data = env->algo_data->current->content;
	env->algo_data->data_tmp = env->algo_data->tmp->content;
	if (env->algo_data->data->value > env->algo_data->data_tmp->value)
	{
		tmp = env->algo_data->data->n_index;
		env->algo_data->data->n_index = env->algo_data->data_tmp->n_index;
		env->algo_data->data_tmp->n_index = tmp;
	}
}

t_list	*find_elem_index(t_env *env, int index, char lst)
{
	t_list	*current;
	t_data	*data;

	if (lst == 'a')
		current = *env->begin_a;
	else
		current = *env->begin_b;
	while (current)
	{
		data = current->content;
		if (data->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	find_neighbor(t_env *env, int n_index)
{
	int	res;

	if (n_index < find_lowest(env, 'b'))
		return (highest_index(env, 'b'));
	res = n_index - 1;
	env->algo_data->current = find_elem_nindex(env, res, 'b');
	while (!env->algo_data->current && res >= 0)
	{
		res--;
		env->algo_data->current = find_elem_nindex(env, res, 'b');
	}
	env->algo_data->data = env->algo_data->current->content;
	return (env->algo_data->data->index);
}

int	scenario_cost(t_env *env, int index_a)
{
	int	cost_a;
	int	cost_b;
	int	neighbor;

	calculate_rotations(env, index_a, env->size_a / 2, 'a');
	cost_a = env->rot_data_a->reps;
	env->algo_data->current_prospect_a = index_a;
	env->algo_data->current = find_elem_index(env, index_a, 'a');
	env->algo_data->data = env->algo_data->current->content;
	neighbor = find_neighbor(env, env->algo_data->data->n_index);
	calculate_rotations(env, neighbor, env->size_b / 2, 'b');
	cost_b = env->rot_data_b->reps;
	if (env->rot_data_a->rev == env->rot_data_b->rev)
		return ((cost_a + cost_b) - min(cost_a, cost_b));
	return (cost_a + cost_b);
}

void	plot_best_move(t_env *env)
{
	int	i;
	int	current;
	int	best_cost;
	int	best_index;

	i = 0;
	best_cost = INT32_MAX;
	best_index = 0;
	while (i < env->size_a)
	{
		current = scenario_cost(env, i);
		if (current < best_cost)
		{
			best_cost = current;
			best_index = i;
		}
		i++;
	}
	env->next_move = best_index;
}
