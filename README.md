*This project has been created as part of the 42 curriculum by hhurnik.*

# push_swap

## Description

push_swap is an algorithmic sorting project written in C.

The program receives a list of unique integers and generates a sequence of stack operations that sorts them in ascending order using two stacks: `a` and `b`.

The main challenge is not only to sort the values correctly, but also to reduce the number of operations used.

The project focuses on:

- sorting algorithms
- algorithmic complexity
- stack manipulation
- input parsing and validation
- target selection
- operation cost calculation
- dynamic memory management

## Operations

The program can use the following operations:

| Operation | Description |
| --- | --- |
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the first element of stack B onto stack A |
| `pb` | Push the first element of stack A onto stack B |
| `ra` | Rotate stack A |
| `rb` | Rotate stack B |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Algorithm

Small stacks are handled with dedicated sorting logic.

For larger inputs, the program:

1. Moves elements from stack A to stack B.
2. Determines target positions between the two stacks.
3. Calculates the cost of moving each candidate.
4. Selects the move with the lowest calculated cost.
5. Rotates the stacks and performs the push.
6. Sorts the remaining elements in stack A.
7. Moves elements back from stack B to their correct positions in stack A.
8. Rotates stack A so that the smallest value is placed at the top.

## Build

Clone the repository and compile the project:

```bash
git clone https://github.com/hhurnik/Push_swap.git
cd Push_swap
make
```

This creates the executable:

```text
push_swap
```

The project includes its required `libft` dependency, which is built automatically by the main Makefile.

## Usage

Pass a list of unique integers:

```bash
./push_swap 4 1 3 2
```

Example output:

```text
pb
sa
ra
pa
ra
```

Arguments may also contain multiple numbers:

```bash
./push_swap "4 1" "3 2"
```

If the input is already sorted, the program prints nothing:

```bash
./push_swap 1 2 3
```

## Input Validation

The program handles invalid input, including:

- duplicate values
- non-numeric arguments
- values outside the signed integer range
- empty or whitespace-only arguments

Example:

```bash
./push_swap 1 1 2
```

Output:

```text
Error
```

## Makefile Rules

```bash
make
```

Builds `push_swap` and the required `libft`.

```bash
make clean
```

Removes object files.

```bash
make fclean
```

Removes object files, libraries and the executable.

```bash
make re
```

Performs a complete rebuild.

## Main Components

- `main.c` — program entry point and initialization
- `parsing.c`, `parsing_utils.c`, `input_validation.c` — argument parsing and validation
- `operations.c`, `reverse_operations.c`, `push_operations.c` — stack operations
- `sort_small.c` — dedicated sorting for small stacks
- `push_swap.c`, `sorting.c` — main sorting flow
- `target_a.c`, `target_b.c` — target position selection
- `costs.c` — operation cost calculation
- `libft/` — supporting C library

## Testing

The implementation was tested with:

- sorted and reverse-sorted inputs
- positive and negative integers
- `INT_MIN` and `INT_MAX`
- duplicate values
- invalid and empty arguments
- numbers passed in separate or combined arguments
- randomized sorting tests

A randomized test suite verified 950 generated inputs with stack sizes from 2 to 20.

Memory handling was also checked with Valgrind, with all allocated memory successfully freed after execution.
