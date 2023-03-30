/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:13:27 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/24 18:57:26 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *arg)
{
	while (*arg != '\0')
	{
		if (ft_isdigit(*arg) || *arg == ' ' || *arg == '-')
		{
			if (*arg == '-' && (*(arg + 1) == ' ' || *(arg + 1) == '\0'))
				return (FAILURE);
			arg++;
		}
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	validate_input(t_env *env, double val)
{
	t_list	*current;
	t_data	*content;

	if (val < -2147483648 || val > 2147483647)
		return (FAILURE);
	current = *env->begin_a;
	while (current)
	{
		content = current->content;
		if (content->value == val)
			return (FAILURE);
		current = current->next;
	}
	return (SUCCESS);
}

static int	parse_single(char **av, t_env *env)
{
	int		index;
	t_data	*n_data;

	env->args = ft_split(av[1], ' ');
	env->size_a = 0;
	index = 0;
	while (env->args[index])
	{
		n_data = (t_data *)ft_calloc(1, sizeof(t_data *));
		if (!n_data || validate_input(env,
				ft_atoi(env->args[index])) == FAILURE)
		{
			free_split(env->args);
			free(n_data);
			return (FAILURE);
		}
		n_data->value = ft_atoi(env->args[index]);
		n_data->index = index++;
		ft_lstadd_back(env->begin_a, ft_lstnew(n_data));
		env->size_a++;
	}
	free_split(env->args);
	return (SUCCESS);
}

static int	parse_multiple(char **av, t_env *env)
{
	int		index;
	t_data	*n_data;

	env->args = av + 1;
	env->size_a = 0;
	index = 0;
	while (env->args[index])
	{
		n_data = (t_data *)ft_calloc(1, sizeof(t_data *));
		if (!n_data)
			return (FAILURE);
		n_data->value = ft_atoi(env->args[index]);
		if (validate_input(env, n_data->value) == FAILURE)
		{
			free(n_data);
			return (FAILURE);
		}
		n_data->index = index++;
		ft_lstadd_back(env->begin_a, ft_lstnew(n_data));
		env->size_a++;
	}
	return (SUCCESS);
}

int	parse_args(int ac, char **av, t_env *env)
{
	int	res;

	if (ac == 2)
	{
		if (check_string(av[1]) == 1)
			return (FAILURE);
		res = parse_single(av, env);
	}
	else
		res = parse_multiple(av, env);
	return (res);
}
