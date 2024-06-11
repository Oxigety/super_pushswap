/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:49:53 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/19 19:49:54 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ra(t_stack **m_stack_a, bool print)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *m_stack_a;
	tmp = *m_stack_a;
	if (current == NULL || current->next == NULL)
		return ;
	*m_stack_a = (*m_stack_a)->next;
	(*m_stack_a)->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
	tmp->next = NULL;
	tmp->prev = current;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **m_stack_b, bool print)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *m_stack_b;
	tmp = *m_stack_b;
	if (current == NULL || current->next == NULL)
		return ;
	*m_stack_b = (*m_stack_b)->next;
	(*m_stack_b)->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
	tmp->next = NULL;
	tmp->prev = current;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **m_stack_a, t_stack **m_stack_b)
{
	ra(m_stack_a, false);
	rb(m_stack_b, false);
	ft_printf("rr\n");
}

void	rotate_a_b(t_stack **m_head_a, t_stack **m_head_b, t_stack *cheapest)
{
	while (*m_head_a != cheapest && *m_head_b != cheapest->target)
		rr(m_head_a, m_head_b);
	set_index(*m_head_a);
	set_index(*m_head_b);
}
