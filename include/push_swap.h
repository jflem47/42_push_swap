/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:09:27 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/30 15:51:32 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE 1

# include "ft_printf.h"
# include "libft.h"

//STRUCTS
typedef struct s_data
{
	double			value;
	int				index;
	int				n_index;
}					t_data;

typedef struct s_rotation_data
{
	int				rev;
	int				reps;
}					t_rotation_data;

typedef struct s_algo_data
{
	t_list			*current;
	t_list			*b;
	t_list			*tmp;
	t_data			*data_b;
	t_data			*data_tmp;
}					t_algo_data;

typedef struct s_env
{
	char			**args;
	t_list			**begin_a;
	t_list			**begin_b;
	int				size_a;
	int				size_b;
	int				highest;
	int				lowest;
	t_algo_data		*algo_data;
	t_rotation_data	*rotation_data;
}					t_env;

//UTILS
int					parse_args(int ac, char **av, t_env *env);
void				free_all(t_list **lst);
void				free_split(char **args);
int					is_sorted(t_env *env);
int					find_highest(t_env *env);
void				free_exit(t_env *env);
int					highest_index(t_env *env);
int					lowest_index(t_env *env);
int					absolute(int x);
void				update_index(t_env *env);
int					find_lowest(t_env *env);

//OPERATIONS
void				sa(t_env *env);
void				sb(t_env *env);
void				ss(t_env *env);
void				pa(t_env *env);
void				pb(t_env *env);
void				ra(t_env *env);
void				rb(t_env *env);
void				rr(t_env *env);
void				rra(t_env *env);
void				rrb(t_env *env);
void				rrr(t_env *env);

//DEBUG
void				test_operations(t_env *env);

//ALGORITHMS
void				push_swap(t_env *env);
void				small_size(t_env *env);
void				large_size(t_env *env);
void				sort_3(t_env *env);
void				sort_2(t_env *env);

#endif