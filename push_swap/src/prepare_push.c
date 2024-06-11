/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:07:35 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/20 14:07:36 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_stack *m_head)
{
	int	i;
	int	median;

	i = 0;
	if (m_head == NULL)
		return ;
	median = stack_len(m_head) * 0.5;
	while (m_head != NULL)
	{
		m_head->current_pos = i;
		if (i <= median)
			m_head->above_m = true;
		else
			m_head->above_m = false;
		m_head = m_head->next;
		i++;
	}
}

void	prepare_push(t_stack **m_head, t_stack *new_head, char stack)
{
	while (*m_head != new_head)
	{
		if (stack == 'A')
		{
			if (new_head->above_m)
				ra(m_head, true);
			else
				rra(m_head, true);
		}
		else if (stack == 'B')
		{
			if (new_head->above_m)
				rb(m_head, true);
			else
				rrb(m_head, true);
		}
	}
}

void	update_nodes_a(t_stack *m_head_a, t_stack *m_head_b)
{
	set_index(m_head_a);
	set_index(m_head_b);
	search_target_a(m_head_a, m_head_b);
	check_cost(m_head_a, m_head_b);
	set_cheapest(m_head_a);
}

void	update_nodes_b(t_stack *m_head_a, t_stack *m_head_b)
{
	set_index(m_head_a);
	set_index(m_head_b);
	search_target_b(m_head_a, m_head_b);
}

void	min_on_top(t_stack **m_head)
{
	t_stack	*min;

	min = find_min(*m_head);
	while ((*m_head)->data != min->data)
	{
		if (min->above_m)
			ra(m_head, true);
		else
			rra(m_head, true);
	}
}
