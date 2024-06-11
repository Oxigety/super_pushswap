/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:09:50 by lchapard          #+#    #+#             */
/*   Updated: 2024/02/20 14:09:50 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	invalid_arg(t_stack *m_head_a)
{
	t_stack	*m_head_b;
	char	**get_argv;
	int		get_argc;
	int		get_split;

	m_head_b = NULL;
	write(STDERR_FILENO, "Error\n", 6);
	free_push_swap(&m_head_a, &m_head_b);
	get_argv = save_argv(NULL);
	get_argc = save_argc(0);
	get_split = save_split(-1);
	if (get_split)
		free_split(get_argv, get_argc);
	exit(EXIT_FAILURE);
	return (0);
}

int	check_inv_nb(t_stack *m_head_a)
{
	t_stack	*current;
	t_stack	*next;

	current = m_head_a;
	next = m_head_a->next;
	while (current != NULL && next != NULL)
	{
		while (next != NULL)
		{
			if (current->data == next->data)
				return (1);
			next = next->next;
		}
		current = current->next;
		next = current->next;
	}
	return (0);
}

int	ft_atoi(t_stack *head, char *str, int sign, long int total)
{
	size_t	i;
	int		valid;	

	i = 0;
	valid = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			sign *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		total = total * 10 + (str[i++] - 48);
		if ((total > 2147483648 && sign < 0) || (total > 2147483647
				&& sign > 0))
			return (invalid_arg(head));
		valid = 1;
	}
	if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		invalid_arg(head);
	if (!valid)
		invalid_arg(head);
	return (total * sign);
}
