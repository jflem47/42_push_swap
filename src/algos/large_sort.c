#include "push_swap.h"

t_list *find_elem(t_env *env, int index)
{
	t_list *current;
	t_data *data;

	current = *env->begin_a;
	data = NULL;
	while (current)
	{
		data = current->content;
		if (index == data->n_index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void bubble_sort(t_env *env)
 {
	int	i;
	int	j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < env->size_a - 1)
	{
		j = 0;
		while (j < env->size_a - i - 1)
		{
			env->algo_data->current = find_elem(env, j);
			env->algo_data->tmp = find_elem(env, j + 1);
			env->algo_data->data = env->algo_data->current->content;
			env->algo_data->data_tmp = env->algo_data->tmp->content;
			if (env->algo_data->data->value > env->algo_data->data_tmp->value)
			{
				tmp = env->algo_data->data->n_index;
				env->algo_data->data->n_index = env->algo_data->data_tmp->n_index;
				env->algo_data->data_tmp->n_index = tmp;
			}
			j++;
		}
		i++;
	}
 }

 static void rotate_best(t_env *env, t_algo_data *data)
 {
	int i;

	i = 0;
	calculate_rotations(env, data->best_index, env->size_a / 2, 'a');
	while (i < env->rotation_data->reps)
	{
		if (env->rotation_data->rev == 1)
			rra(env);
		else
			ra(env);
		i++;
	}
	pb(env);
 }

void make_best_move(t_env *env, int min, int max)
{
	int moves;
	int i;
	t_algo_data data;

	i = min;
	moves = INT32_MAX;
	while (i < max)
	{
		data.current = find_elem(env, i);
		if (data.current)
		{
			data.data = data.current->content;
			data.index = data.data->index;
			calculate_rotations(env, data.index, env->size_a / 2, 'a');
			if (env->rotation_data->reps < moves)
			{
				moves = env->rotation_data->reps;
				data.best_index = data.index;
			}
		}
		i++;
	}
	rotate_best(env, &data);
}
