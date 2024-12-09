/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:14:41 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 20:31:56 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// instruct
void	sa(int **stack_a, int *size_a); // norminette OK
void	sb(int **stack_b, int *size_b);
void	ss(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	ra(int **stack_a, int *size_a);
void	rb(int **stack_b, int *size_b);

// instruct2
void	rr(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	rra(int **stack_a, int *size_a);
void	rrb(int **stack_b, int *size_b);
void	rrr(int **stack_a, int **stack_b, int *size_a, int *size_b);

// instruct3
void	shift_elements(int *stack, int size, int direction);
int		safe_realloc_stack(int **stack, int old_size, int new_size);
void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	pb(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// push
void	sort_two(int **stack_a, int *size_a);
void	sort_three(int **stack_a, int *size_a);
void	fourth(int **stack_a, int **stack_b, int *size_a, int *size_b); // vs
void	fourth_pierwsze(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	push_first_two(int **stack_a, int **stack_b, int *size_a, int *size_b);

// target
int		find_closest_smaller_id(int stack_a_elem, int *stack_b, int size_b);
int		find_max_value_id(int *stack_b, int size_b);
int		find_closest_smaller_id(int stack_a_elem, int *stack_b, int size_b);
int		**initialize_pairs(int size);
int		**find_target(int *stack_a, int *stack_b, int size_a, int size_b);

// target_a
int		find_closest_bigger(int stack_b_elem, int *stack_a, int size_a);
int		find_min_value_id(int *stack_a, int size_a);
int		find_closest_bigger_id(int stack_b_elem, int *stack_a, int size_a);
int		**find_target_a(int *stack_a, int *stack_b, int size_a, int size_b);

// costs
void	calculate_individual_costs(int *pair, int *cost, int size_a,
			int size_b);
int		**calculate_costs(int **pairs, int size_a, int size_b);
int		*calculate_costs_sum(int **costs, int size_a);
int		*min_cost(int **pairs, int size_a, int size_b);
int		min_cost_id(int **pairs, int size_a, int size_b);

// sort_2_3_4
void	sort_two(int **stack_a, int *size_a);
void	sort_three(int **stack_a, int *size_a);
void	fourth(int **stack_a, int **stack_b, int *size_a, int *size_b);

// push_swap
void	push_first_two(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	rotate_a(int *the_pair, int median_a, int **stack_a, int *size_a);
void	rotate_b(int *the_pair, int median_b, int **stack_b, int *size_b);
void	rotate_both(int *the_pair, int **stacks[], int *size_a, int *size_b);
void	move_up(int **pairs, int **stacks[], int *size_a, int *size_b);

// push_swap2
void	handle_small_stacks(int **stack_a, int **stack_b, int *size_a,
			int *size_b);
void	handle_large_stack(int **stack_a, int **stack_b, int *size_a,
			int *size_b);
void	perform_rotation(int **stack_a, int *size_a, int id_stack_a);
void	back_to_stack_a(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	final_sort(int **stack_a, int **stack_b, int *size_a, int *size_b);

/////// parsing
// parse
int		are_all_arguments_empty(int argc, char **argv);
int		is_in_int_range(char *str);
int		is_sorted(int *stack, int size);
void	display_error(void);
int		ft_isspace(char c);

// parse2
int		is_valid_int(char *str);
int		words_counter(char *s);
char	**ft_split_words(char *s);
int		calculate_size(int argc, char **argv);
int		*allocate_result(int size);

// parse3
void	validate_and_free_words(char **words, int *result);
void	split_and_process_words(char *arg, int *result, int *count);
void	process_words(int argc, char **argv, int *result);
int		*parse_input(int argc, char **argv, int *size);
int		is_duplicate(int *stack_a, int size);

// parse4
int		*validate_and_parse(int argc, char **argv, int *size);
int		*initialize_and_parse(int argc, char **argv, int *size_a);

#endif
