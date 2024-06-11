/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:51:51 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:51:52 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	find_max_rank(t_stack *m_head_a)
{
	int	temp;

	temp = m_head_a->data;
	m_head_a = m_head_a->next;
	while (m_head_a != NULL)
	{
		if ((m_head_a->data) > temp)
			temp = m_head_a->data;
		m_head_a = m_head_a->next;
	}
	return (temp);
}

t_stack	*find_max(t_stack *m_head)
{
	t_stack	*max;
	long	temp;

	if (m_head == NULL)
		return (NULL);
	temp = LONG_MIN;
	while (m_head != NULL)
	{
		if ((m_head->data) > temp)
		{
			temp = m_head->data;
			max = m_head;
		}
		m_head = m_head->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *m_head)
{
	t_stack	*min;
	long	temp;

	if (m_head == NULL)
		return (NULL);
	temp = LONG_MAX;
	while (m_head != NULL)
	{
		if ((m_head->data) < temp)
		{
			temp = m_head->data;
			min = m_head;
		}
		m_head = m_head->next;
	}
	return (min);
}

void	search_target_a(t_stack *m_head_a, t_stack *m_head_b)
{
	t_stack	*current;
	t_stack	*target;
	long	best_match;

	while (m_head_a)
	{
		best_match = LONG_MIN;
		current = m_head_b;
		while (current)
		{
			if (current->data < m_head_a->data
				&& current->data > best_match)
			{
				best_match = current->data;
				target = current;
			}
			current = current->next;
		}
		if (best_match == LONG_MIN)
			m_head_a->target = find_max(m_head_b);
		else
			m_head_a->target = target;
		m_head_a = m_head_a->next;
	}
}

void	search_target_b(t_stack *m_head_a, t_stack *m_head_b)
{
	t_stack	*current;
	t_stack	*target;
	long	best_match;

	while (m_head_b)
	{
		best_match = LONG_MAX;
		current = m_head_a;
		while (current)
		{
			if (current->data > m_head_b->data
				&& current->data < best_match)
			{
				best_match = current->data;
				target = current;
			}
			current = current->next;
		}
		if (best_match == LONG_MAX)
			m_head_b->target = find_min(m_head_a);
		else
			m_head_b->target = target;
		m_head_b = m_head_b->next;
	}
}
