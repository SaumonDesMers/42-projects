#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "../libft/src/libft.h"
# include <stdio.h>

typedef struct	s_root
{
	int	*stack;
	int	size;
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_root;

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

void	brutal_sorting(t_root *root);
int		is_sorted(int *stack, int size);

int		get_stack_checker(int ac, char **av, t_root *root);
void	do_op(t_root *root, char *line);
void	sort_stack(t_root *root);
int		check_op(char *op);

void	free_all(t_root *root);

#endif