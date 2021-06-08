#include "push_swap.h"

int	get_stack_checker(int ac, char **av, t_root *root)
{
	int		i;

	root->stack = NULL;
	root->stack_a = malloc(sizeof(int) * ac);
	root->stack_b = malloc(sizeof(int) * ac);
	if (!root->stack_a || !root->stack_b)
	{
		free_all(root);
		return (0);
	}
	root->size = ac - 1;
	root->size_a = root->size;
	root->size_b = 0;
	i = 0;
	while (++i < ac)
		root->stack_a[i - 1] = ft_atoi(av[i]);
	i = 0;
	while (i < root->size)
		root->stack_b[i++] = 0;
	return (1);
}

void	do_op(t_root *root, char *line)
{
	if (!ft_strncmp(line, "sa", 5))
		sa(root, 0);
	else if (!ft_strncmp(line, "sb", 5))
		sb(root, 0);
	else if (!ft_strncmp(line, "ss", 5))
		ss(root, 0);
	else if (!ft_strncmp(line, "pa", 5))
		pa(root, 0);
	else if (!ft_strncmp(line, "pb", 5))
		pb(root, 0);
	else if (!ft_strncmp(line, "ra", 5))
		ra(root, 0);
	else if (!ft_strncmp(line, "rb", 5))
		rb(root, 0);
	else if (!ft_strncmp(line, "rr", 5))
		rr(root, 0);
	else if (!ft_strncmp(line, "rra", 5))
		rra(root, 0);
	else if (!ft_strncmp(line, "rrb", 5))
		rrb(root, 0);
	else if (!ft_strncmp(line, "rrr", 5))
		rrr(root, 0);
}

void	sort_stack(t_root *root)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = ft_gnl(0, &line);
		if (!check_op(line) && ret)
		{
			printf("Error\n");
			return ;
		}
		do_op(root, line);
		free(line);
	}
	if (is_sorted(root->stack_a, root->size_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	check_op(char *op)
{
	if (ft_strncmp(op, "sa", 5)
		&& ft_strncmp(op, "sb", 5)
		&& ft_strncmp(op, "ss", 5)
		&& ft_strncmp(op, "pa", 5)
		&& ft_strncmp(op, "pb", 5)
		&& ft_strncmp(op, "ra", 5)
		&& ft_strncmp(op, "rb", 5)
		&& ft_strncmp(op, "rr", 5)
		&& ft_strncmp(op, "rra", 5)
		&& ft_strncmp(op, "rrb", 5)
		&& ft_strncmp(op, "rrr", 5))
		return (0);
	return (1);
}