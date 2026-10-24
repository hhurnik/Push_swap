/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:05:42 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/04 19:38:48 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	shift_elements(int *stack, int size, int direction)
{
	int	i;

	i = 0;
	if (direction == 1)
	{
		i = size;
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
	}
	else
	{
		while (i < size - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
	}
}

int	safe_realloc_stack(int **stack, int old_size, int new_size)
{
	*stack = ft_realloc(*stack, old_size * sizeof(int), new_size * sizeof(int));
	if (*stack == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (0);
	}
	return (1);
}

void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (*size_b == 0)
		return ;
	if (!safe_realloc_stack(stack_a, *size_a, *size_a + 1))
		return ;
	shift_elements(*stack_a, *size_a, 1);
	(*stack_a)[0] = (*stack_b)[0];
	shift_elements(*stack_b, *size_b, -1);
	(*size_b)--;
	if (*size_b == 0)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	else if (!safe_realloc_stack(stack_b, *size_b + 1, *size_b))
		return ;
	(*size_a)++;
	printf("pa\n");
}

void	pb(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return ;
	if (!safe_realloc_stack(stack_b, *size_b, *size_b + 1))
		return ;
	shift_elements(*stack_b, *size_b, 1);
	(*stack_b)[0] = (*stack_a)[0];
	shift_elements(*stack_a, *size_a, -1);
	(*size_a)--;
	if (*size_a == 0)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else if (!safe_realloc_stack(stack_a, *size_a + 1, *size_a))
		return ;
	(*size_b)++;
	printf("pb\n");
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	size_t	copy_size;
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return ((void *)malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

//////////////////////////////////// TESTER FOR PA, PB
	////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// // Helper function to print the state of the stacks and their sizes
// void print_stacks(int *stack_a, int *stack_b, int size_a, int size_b) {
//     printf("Stack A: ");
//     int i = 0;
//     while (i < size_a) {
//         printf("%d ", stack_a[i]);
//         i++;
//     }
//     printf("\nSize of Stack A: %d\n", size_a);

//     printf("Stack B: ");
//     i = 0;
//     while (i < size_b) {
//         printf("%d ", stack_b[i]);
//         i++;
//     }
//     printf("\nSize of Stack B: %d\n\n", size_b);
// }
// int main() {
//     int size_a = 0, size_b = 0;
//     int *stack_a = NULL, *stack_b = NULL;

//     // Test Case 1: Both stacks are empty
//     printf("Test 1: Both stacks are empty\n");
//     print_stacks(stack_a, stack_b, size_a, size_b);  // Before pa
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Should do nothing
//     print_stacks(stack_a, stack_b, size_a, size_b);  // After pa

//     // Test Case 2: stack_a is empty, stack_b has one element
//     size_b = 1;
//     stack_b = (int *)malloc(size_b * sizeof(int));
//     stack_b[0] = 10;

//     printf("Test 2: stack_a is empty, stack_b has one element\n");
//     print_stacks(stack_a, stack_b, size_a, size_b);  // Before pa
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Should move 10 to stack_a
//     print_stacks(stack_a, stack_b, size_a, size_b);  // After pa

//     // Test Case 3: stack_a is empty, stack_b has multiple elements
//     size_b = 3;
//     stack_b = (int *)malloc(size_b * sizeof(int));
//     stack_b[0] = 20;
//     stack_b[1] = 30;
//     stack_b[2] = 40;

//     printf("Test 3: stack_a is empty, stack_b has multiple elements\n");
//     print_stacks(stack_a, stack_b, size_a, size_b);  // Before pa
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Should move 20 to stack_a
//     print_stacks(stack_a, stack_b, size_a, size_b);  // After pa

//     // Test Case 4: stack_a has multiple elements, stack_b has one element
//     size_a = 3;
//     stack_a = (int *)malloc(size_a * sizeof(int));
//     stack_a[0] = 1;
//     stack_a[1] = 2;
//     stack_a[2] = 3;
//     size_b = 1;
//     stack_b = (int *)malloc(size_b * sizeof(int));
//     stack_b[0] = 10;

//     printf("Test 4: stack_a has multiple elements,
	//stack_b has one element\n");
//     print_stacks(stack_a, stack_b, size_a, size_b);  // Before pa
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Should move 10 to stack_a
//     print_stacks(stack_a, stack_b, size_a, size_b);  // After pa

//     // Test Case 5: stack_b becomes empty after pa
//     printf("Test 5: stack_b becomes empty after pa\n");
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Move 30 to stack_a
//     pa(&stack_a, &stack_b, &size_a, &size_b);  // Move 40 to stack_a
//     print_stacks(stack_a, stack_b, size_a, size_b);  // After pa

//     // Test Case 6: Simulating realloc failure
//     printf("Test 6: Simulating memory allocation failure for realloc\n");
//     free(stack_a);   // Clean up stack_a
//     stack_a = NULL;  // Simulate no memory left for realloc

//     // Should print an error message in the `pa()` function
//     pa(&stack_a, &stack_b, &size_a, &size_b);
// //Should handle memory allocation failure
//     print_stacks(stack_a, stack_b, size_a, size_b);
// //After pa (will likely exit program due to failure)

//     // Clean up allocated memory
//     free(stack_a);
//     free(stack_b);

//     return (0);
// }