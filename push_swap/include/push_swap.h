/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:40:07 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/19 10:40:09 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
	int				current_pos;
	int				push_price;
	bool			above_m;
	bool			is_cheapest;
	struct s_stack	*target;
};
typedef struct s_stack	t_stack;

int		ft_atoi(t_stack *head, char *str, int sign, long int total);
void	free_push_swap(t_stack **head_a, t_stack **head_b);
void	fill_a(t_stack **head, char **argv, int argc);
void	free_split(char **argv, int argc);
int		check_inv_nb(t_stack *m_head_a);
char	**ft_split(char const *s, char c, int *argc, int current_word);
char	**save_argv(char **argv);
int		save_argc(int argc);
bool	save_split(int split);
int		stack_len(t_stack *m_head);
void	check_cost(t_stack *m_head_a, t_stack *m_head_b);
void	set_cheapest(t_stack *m_head);
t_stack	*find_cheapest(t_stack *m_head_a);
int		find_max_rank(t_stack *m_head_a);
t_stack	*find_max(t_stack *m_head);
t_stack	*find_min(t_stack *m_head);
void	search_target_a(t_stack *m_head_a, t_stack *m_head_b);
void	search_target_b(t_stack *m_head_a, t_stack *m_head_b);
int		invalid_arg(t_stack *m_head_a);
void	set_index(t_stack *m_head);
void	prepare_push(t_stack **m_head, t_stack *new_head, char stack);
void	update_nodes_a(t_stack *m_head_a, t_stack *m_head_b);
void	update_nodes_b(t_stack *m_head_a, t_stack *m_head_b);
void	min_on_top(t_stack **m_head);
int		is_in_order(t_stack *m_head_a);
void	sort_three(t_stack **m_head_a, t_stack **m_head_b, bool freed);
void	sort_stacks(t_stack **m_head_a, t_stack **m_head_b);
void	sort_two(t_stack **m_head_a, t_stack **m_head_b);
int		stack_init(t_stack **m_head_a, t_stack **m_head_b,
			char **argv, int argc);
void	pa(t_stack **m_stack_a, t_stack **m_stack_b, bool print);
void	pb(t_stack **m_stack_a, t_stack **m_stack_b, bool print);
void	rotate_push_a(t_stack **m_head_a, t_stack **m_head_b);
void	rotate_push_b(t_stack **m_head_a, t_stack **m_head_b);
void	rra(t_stack **m_stack_a, bool print);
void	rrb(t_stack **m_stack_b, bool print);
void	rrr(t_stack **m_stack_a, t_stack **m_stack_b);
void	r_rotate_a_b(t_stack **m_head_a, t_stack **m_head_b, t_stack *cheapest);
void	rotate_a_b(t_stack **m_head_a, t_stack **m_head_b, t_stack *cheapest);
void	rr(t_stack **m_stack_a, t_stack **m_stack_b);
void	rb(t_stack **m_stack_b, bool print);
void	ra(t_stack **m_stack_a, bool print);
void	sa(t_stack **head_a, bool print);
void	sb(t_stack **head_b, bool print);
void	ss(t_stack **m_stack_a, t_stack **m_stack_b);
bool	save_split(int split);
int		save_argc(int argc);
char	**save_argv(char **argv);

#endif
