#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "../libft/src/libft.h"
# include <stdio.h>

typedef int	t_bool;

typedef struct s_root
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_root;

typedef struct s_sort_sample
{
	int	size_a[64000];
	int	nb_a;
	int	size_b[64000];
	int	nb_b;
}	t_sample;

int		check_arg(int ac, char **av);
int		get_stack(int ac, char **av, t_root *root);

void	sa(t_root *root, int flag);
void	sb(t_root *root, int flag);
void	ss(t_root *root, int flag);
void	pa(t_root *root, int flag);
void	pb(t_root *root, int flag);
void	ra(t_root *root, int flag);
void	rb(t_root *root, int flag);
void	rr(t_root *root, int flag);
void	rra(t_root *root, int flag);
void	rrb(t_root *root, int flag);
void	rrr(t_root *root, int flag);

void	sort_iterative(t_root *root);
int		get_median(int *stack, int size);
void	push_sample_back_on_a(t_sample *sample, t_root *root);
void	sort_sample(t_sample *sample, t_root *root);
void	push_lower_half_a_to_b(t_sample *sample, t_root *root);
void	push_upper_half_b_to_a(t_sample *sample, t_root *root);

void	sorting_size_three(t_root *root);
int		wich_list(int n1, int n2, int n3, t_root *root);

void	sorting_size_five(t_root *root);

int		get_stack_checker(int ac, char **av, t_root *root);
void	do_op(t_root *root, char *line);
void	sort_stack(t_root *root);
int		check_op(char *op);

int		is_sorted(int *stack, int size);
int		free_all(t_root *root, int ret);

#endif