#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	int				above_median;
	double			disorder;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
typedef struct s_info
{
	int				ch_size;
	int				up;
	int				low;
	int				pos;
	int				count;
	int				k;
}	t_info;

typedef struct s_a_state
{
	t_stack			**a;
	int				size;
	t_stack			*tail;
}	t_a_state;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;
void	ft_error(t_stack **stack, char **arr);
int		check_spaces(char *str);
long	ft_atoi_strict(char *str, t_stack **stack, char **arr);
long	atoi_loop(char *str,t_stack **stack,char **arr,int sign);
t_stack	*stack_new(int value);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);
void	free_string_array(char **arr);
void	init_stack_a(int argc, char **argv, t_stack **stack_a);
void	check_duplicates(t_stack **stack);

void    print_stack(t_stack *stack);

void ft_swap(t_stack **ab);
void    sa(t_stack **a, int *counts);
void    sb(t_stack **b, int *counts);
void    ss(t_stack **a, t_stack **b, int *counts);
void    pa(t_stack **b, t_stack **a, int *counts);
void    pb(t_stack **a, t_stack **b, int *counts);
void    ft_rotate(t_stack **ab);
void    ra(t_stack **a, int *counts);
void    rb(t_stack **b, int *counts);
void    rr(t_stack **a, t_stack **b, int *counts);
void    ft_reverse_rotate(t_stack **a);
void    rra(t_stack **a, int *counts);
void    rrb(t_stack **b, int *counts);
void    rrr(t_stack **a, t_stack **b, int *counts);

int ft_stack_size(t_stack *ab);
int find_min_pos(t_stack *a);
void    ft_simple_algo(t_stack **a, t_stack **b, int *counts);
void    simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b,
		int *counts);

void	quick_sort_a(t_stack **a,t_stack **b,int size, int *counts);
void	quick_sort_b(t_stack **a,t_stack **b,int size, int *counts);
int		pivot_loop(t_stack *a, int *stackar, int size);
void	loop_b(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts);
void	loop_a(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts);
int		find_max_val(t_stack *a,int size);
int		find_min_val(t_stack *a,int size);
int		get_pivot(t_stack *a,int size);

void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b, int size);
int		leading_flags(int argc, char **argv, int *bench, char **algo);
void	print_bench(double disorder, int *counts);


void		medium_algo(t_stack **a, t_stack **b, int n, int *counts);
void		chunk_sort(t_stack **a, t_stack **b, t_info *info, int *counts);
void		process_chunk(t_a_state *st, t_stack **b, t_info *info,
				int *counts);
void		move_one(t_a_state *st, t_stack **b, t_info *info, int *counts);
int			compute_dist(t_a_state *st, t_info *info, int *res_pos,
				int *res_index);
t_stack		*scan_front(t_stack *head, t_info *info, int *pos_f);
t_stack		*scan_back(t_stack *tail, t_info *info, int *pos_b);
int			insertion_depth(t_stack *b, int placed, int index);
void		rotate_extraction(t_a_state *st, t_stack **b, int forward,
				int *cost_a, int *depth, int *counts);
void		merge_forward(t_a_state *st, t_stack **b, int *cost_a,
				int *depth, int *counts);
int			chunk_count(int n);
t_stack		*find_tail(t_stack *a);


void	heap_utils(t_stack **a, int size);
void	sort_heap(t_stack **arr, int size);
void	sift_down(t_stack **arr, int size, int i);
void	assign_index(t_stack **arr, int size);
void	add_pos(t_stack	**a);

void	ft_adaptive(t_stack **a, t_stack **b, int size, int *counts);
double	ft_disorder(t_stack *a, int size);

int root(int num);
int ft_isqrt(int n);

#endif
