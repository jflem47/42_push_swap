#include "push_swap.h"

static t_list *find_elem(t_env *env, int index)
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
	return (*env->begin_a);
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