#include "minishell.h"

void	ft_ast0(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent);
void	ft_ast1(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent);
void	ft_ast2(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent);

int	main(int ac, char **av, char **env)
{
	t_root	root;
	t_ast	ast0;
	t_ast	ast1;
	t_ast	ast2;

	root.shell_env = env;
	root.ast_start = &ast0;

	ft_ast0(&ast0, &ast1, &ast2, NULL);
	ft_ast1(&ast1, NULL, NULL, &ast0);
	ft_ast2(&ast2, NULL, NULL, &ast0);

	ast_set_index(&ast0);
	scan_ast(&open_fd, &ast0, &root);

	scan_ast(&exec_all_cmd, &ast0, &root);

	scan_ast(&close_fd, &ast0, &root);

	free_split(ast1.cmd);
	free_split(ast2.cmd);
	return(0);
}

void	ft_ast0(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent)
{
	ast->parent = parent;
	ast->left = left;
	ast->right = right;
	ast->pid = 0;
	ast->type = _OPERATOR;
	ast->operator = "|";
	ast->cmd = NULL;
	ast->file = NULL;
	ast->limiter = NULL;
	ast->fd_in = 0;
	ast->fd_out = 1;
	ast->index = 0;
}

void	ft_ast1(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent)
{
	ast->parent = parent;
	ast->left = left;
	ast->right = right;
	ast->pid = 0;
	ast->type = _CMD;
	ast->operator = NULL;
	ast->cmd = ft_split("/bin/ls", ' ');
	ast->file = NULL;
	ast->limiter = NULL;
	ast->fd_in = 0;
	ast->fd_out = 1;
	ast->index = 0;
}

void	ft_ast2(t_ast *ast, t_ast *left, t_ast *right, t_ast *parent)
{
	ast->parent = parent;
	ast->left = left;
	ast->right = right;
	ast->pid = 0;
	ast->type = _CMD;
	ast->operator = NULL;
	ast->cmd = ft_split("/usr/bin/grep ft", ' ');
	ast->file = NULL;
	ast->limiter = NULL;
	ast->fd_in = 0;
	ast->fd_out = 1;
	ast->index = 0;
}
