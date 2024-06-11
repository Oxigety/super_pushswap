/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:36 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/20 14:06:37 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	check_cost(t_stack *m_head_a, t_stack *m_head_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_len(m_head_a);
	size_b = stack_len(m_head_b);
	while (m_head_a)
	{
		m_head_a->push_price = m_head_a->current_pos;
		if (!(m_head_a->above_m))
		{
			m_head_a->push_price = size_a - (m_head_a->current_pos);
		}
		if (m_head_a->target->above_m)
		{
			m_head_a->push_price += m_head_a->target->current_pos;
		}
		else
		{
			m_head_a->push_price += size_b - (m_head_a->target->current_pos);
		}
		m_head_a = m_head_a->next;
	}
}

void	set_cheapest(t_stack *m_head)
{
	t_stack	*cheapest;
	long	cheapest_value;

	if (m_head == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (m_head != NULL)
	{
		if (m_head->push_price < cheapest_value)
		{
			cheapest_value = m_head->push_price;
			cheapest = m_head;
		}
		m_head = m_head->next;
	}
	cheapest->is_cheapest = true;
}

t_stack	*find_cheapest(t_stack *m_head_a)
{
	t_stack	*current;

	current = m_head_a;
	while (current != NULL)
	{
		if ((current->is_cheapest) == true)
			return (current);
		current = current->next;
	}
	return (NULL);
}
