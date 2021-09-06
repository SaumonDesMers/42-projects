#include "minishell.h"

void	open_fd(t_ast *ast, t_root *root)
{
	int	pipe[2];

	if (ast->type == OPERATOR)
	{
		if (ft_strncmp(ast->operator, "|", 2) == 0
			|| ft_strncmp(ast->operator, "<<", 3) == 0)
		{
			error_catch(pipe(ast->pipe) == -1, "fail to open pipe", root);
			ast->fd_in = pipe[0];
			ast->fd_out = pipe[1];
		}
		if (ft_strncmp(ast->operator, ">", 2) == 0)
		{
			ast->fd_out = open(ast->right->file, O_WRONLY | O_TRUNC);
			if (ast->fd_out == -1)
				ast->fd_out = open(ast->right->file, O_WRONLY | O_CREAT, 0664);
			error_catch(ast->fd_out == -1, "fail to open output file", root);
		}
		if (ft_strncmp(ast->operator, ">>", 2) == 0)
		{
			ast->fd_out = open(ast->right->file, O_WRONLY | O_APPEND);
			if (ast->fd_out == -1)
				ast->fd_out = open(ast->right->file, O_WRONLY | O_CREAT, 0664);
			error_catch(ast->fd_out == -1, "fail to open output file", root);
		}
		if (ft_strncmp(ast->operator, "<", 2) == 0)
		{
			ast->fd_in = open(ast->left->file, O_RDONLY);
			error_catch(fd_in == -1, "fail to open input file", root);
		}
	}
}

void	close_fd(t_ast *ast, t_root *root)
{
	if (ast->type == OPERATOR)
	{
		if (ft_strncmp(ast->operator, "|", 2) == 0
			|| ft_strncmp(ast->operator, "<<", 3) == 0)
		{
			close(ast->fd_in);
			close(ast->fd_out);
		}
		if (ft_strncmp(ast->operator, ">", 2) == 0
			|| ft_strncmp(ast->operator, ">>", 3) == 0)
			close(ast->fd_out);
		if (ft_strncmp(ast->operator, "<", 2) == 0)
			close(ast->fd_in);
	}
}

void	scan_ast(void (*fct)(t_ast, t_root), t_ast *ast, t_root *root)
{
	fct(ast, root);
	if (ast->left)
		scan_ast(fct, ast->left, root);
	if (ast->right)
		scan_ast(fct, ast->right, root);
}

t_ast	*search_index(t_ast *ast, int index)
{
	static t_ast *ast_return;

	if (ast->index == index)
		ast_return == ast;
	if (ast->left)
		search_index(fct, ast->left);
	if (ast->right)
		search_index(fct, ast->right);
	return (ast_return);
}

int	read_heredoc_pipe(int heredoc_pipe[2])
{
	int		heredoc_pipe[2];
	char	*line;

	while (1)
	{
		line = readline("pipe heredoc>");
		// check line not NULL
		if (!ft_strncmp(line, lst->next->str, ft_strlen(lst->next->str) + 1))
			break ;
		ft_putstr_fd(line, heredoc_pipe[1]);
		ft_putstr_fd("\n", heredoc_pipe[1]);
		free(line);
		line = NULL;
	}
	free(line);
	close(heredoc_pipe[1]);
	return (heredoc_pipe[0])
}

void	exec_all_cmd(t_ast *ast, t_root *root)
{
	t_ast *ast_output;
	t_ast *ast_input;
	t_ast *ast_input_stop;

	if (ast->type == CMD)
	{
		ast_output = search_index(root->ast_start, ast->index + 1)->parent;
		ast_input_stop = ast_output;
		while (1)
		{
			ast_input = ast->parent;
			while (ast_input != ast_input_stop)
			{
				exec_cmd(ast, ast_input->fd_in, ast_output->fd_out, root);
				ast_input = ast_input->parent;
			}
			if (ft_strncmp(ast_output->operator, "|", 2) == 0)
				break ;
			ast_output = ast_output->parent;
		}
	}
}
