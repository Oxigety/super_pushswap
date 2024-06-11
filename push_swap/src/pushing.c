/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:48:47 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:48:49 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **m_stack_a, t_stack **m_stack_b, bool print)
{
	t_stack	*new_stack;

	if (*m_stack_b == NULL)
		return ;
	new_stack = *m_stack_b;
	*m_stack_b = (*m_stack_b)->next;
	if (*m_stack_b != NULL)
		(*m_stack_b)->prev = NULL;
	new_stack->next = *m_stack_a;
	if (*m_stack_a != NULL)
		(*m_stack_a)->prev = new_stack;
	*m_stack_a = new_stack;
	new_stack->prev = NULL;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **m_stack_a, t_stack **m_stack_b, bool print)
{
	t_stack	*new_stack;

	if (*m_stack_a == NULL)
		return ;
	new_stack = *m_stack_a;
	*m_stack_a = (*m_stack_a)->next;
	if (*m_stack_a != NULL)
		(*m_stack_a)->prev = NULL;
	new_stack->next = *m_stack_b;
	if (*m_stack_b != NULL)
		(*m_stack_b)->prev = new_stack;
	*m_stack_b = new_stack;
	new_stack->prev = NULL;
	if (print)
		ft_printf("pb\n");
}

void	rotate_push_a(t_stack **m_head_a, t_stack **m_head_b)
{
	prepare_push(m_head_a, (*m_head_b)->target, 'A');
	pa(m_head_a, m_head_b, true);
}

void	rotate_push_b(t_stack **m_head_a, t_stack **m_head_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*m_head_a);
	if (cheapest->above_m && cheapest->target->above_m)
		rotate_a_b(m_head_a, m_head_b, cheapest);
	else if ((!cheapest->above_m) && !(cheapest->target->above_m))
		r_rotate_a_b(m_head_a, m_head_b, cheapest);
	prepare_push(m_head_a, cheapest, 'A');
	prepare_push(m_head_b, cheapest->target, 'B');
	pb(m_head_a, m_head_b, true);
}
