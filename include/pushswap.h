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

void	ft_error(t_stack **stack, char **arr);
int		check_spaces(char *str);
long	ft_atoi_strict(char *str, t_stack **stack, char **arr);
t_stack	*stack_new(int value);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);
void	free_string_array(char **arr);
void	init_stack_a(int argc, char **argv, t_stack **stack_a);
void	check_duplicates(t_stack **stack);

void    print_stack(t_stack *stack);

void ft_swap(t_stack **ab);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);
void    ft_rotate(t_stack **ab);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    ft_reverse_rotate(t_stack **a);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

int ft_stack_size(t_stack *ab);
int find_min_pos(t_stack *a);
void    ft_simple_algo(t_stack **a, t_stack **b);
void    simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b);

void	quick_sort_a(t_stack **a,t_stack **b,int size);
void	quick_sort_b(t_stack **a,t_stack **b,int size);
int		find_max_val(t_stack *a,int size);
int		find_min_val(t_stack *a,int size);
int		get_pivot(t_stack *a,int size);

void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b, int size);


int	find_chunk_pos(t_stack *a, t_info *c_info, int size);
void	process_chunk(t_stack **a, t_stack **b, t_info *c_info, int size);
void	next_chunk(t_info *c_info, t_stack **b, t_stack **a);
void	intermittent_bsort(t_stack **b, t_stack **a, t_info *c_info);
void	sort_to_a(int pos, int size, t_stack **b, t_stack **a);
void	medium_algo(t_stack **a, t_stack **b, int argc);


void	heap_utils(t_stack **a, int size);
void	sort_heap(t_stack **arr, int size);
void	sift_down(t_stack **arr, int size, int i);
void	assign_index(t_stack **arr, int size);
void	add_pos(t_stack	**a);

void	ft_adaptive(t_stack **a, t_stack **b, int size);
double	ft_disorder(t_stack *a, int size);

int root(int num);
int ft_isqrt(int n);

#endif
