/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:48:29 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/19 11:48:30 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *m_head)
{
	int		len;

	if (m_head == NULL)
		return (0);
	len = 0;
	while (m_head)
	{
		len++;
		m_head = m_head->next;
	}
	return (len);
}

void	free_split(char **argv, int argc)
{
	int	i;

	i = 1;
	if (argv == NULL)
		return ;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_push_swap(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	while (*head_a != NULL)
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		free(temp);
	}
	while (*head_b != NULL)
	{
		temp = *head_b;
		*head_b = (*head_b)->next;
		free(temp);
	}
}

int	is_in_order(t_stack *m_head_a)
{
	t_stack	*current;
	t_stack	*next;

	current = m_head_a;
	if (current->next == NULL)
		return (1);
	next = m_head_a->next;
	while (current != NULL && next != NULL)
	{
		if (current->data > next->data)
			return (0);
		current = current->next;
		next = current->next;
	}
	return (1);
}

void	fill_a(t_stack **head, char **argv, int argc)
{
	t_stack	*new_stack;
	int		temp;

	(*head)->data = ft_atoi(*head, argv[argc], 1, 0);
	(*head)->is_cheapest = false;
	(*head)->prev = NULL;
	argc--;
	while (argc >= 1)
	{
		temp = ft_atoi(*head, argv[argc], 1, 0);
		new_stack = malloc(sizeof(t_stack));
		if (new_stack == NULL)
			return ;
		new_stack->is_cheapest = false;
		new_stack->data = temp;
		new_stack->next = *head;
		(*head)->prev = new_stack;
		*head = new_stack;
		argc--;
	}
	(*head)->prev = NULL;
}
