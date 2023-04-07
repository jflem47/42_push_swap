/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:04:02 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/22 15:06:01 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
}

void	print_op(int op)
{
	if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
}

void	make_move(int op, t_env *env)
{
	if (op == SA)
		sa(env);
	else if (op == SB)
		sb(env);
	else if (op == SS)
		ss(env);
	else if (op == PA)
		pa(env);
	else if (op == PB)
		pb(env);
	else if (op == RA)
		ra(env);
	else if (op == RB)
		rb(env);
	else if (op == RR)
		rr(env);
	else if (op == RRA)
		rra(env);
	else if (op == RRB)
		rrb(env);
	else if (op == RRR)
		rrr(env);
	print_op(op);
}
