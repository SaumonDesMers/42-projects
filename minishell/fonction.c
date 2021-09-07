#include "minishell.h"

void	open_fd(t_ast *ast, t_root *root)
{
	int	pipe_fd[2];

	if (ast->type == _OPERATOR)
	{
		if (ft_strncmp(ast->operator, "|", 2) == 0
			|| ft_strncmp(ast->operator, "<<", 3) == 0)
		{
			error_catch(pipe(pipe_fd) == -1, "fail to open pipe", root);
			ast->fd_in = pipe_fd[0];
			ast->fd_out = pipe_fd[1];
		}
		else if (ft_strncmp(ast->operator, ">", 2) == 0)
		{
			ast->fd_out = open(ast->right->file, O_WRONLY | O_TRUNC);
			if (ast->fd_out == -1)
				ast->fd_out = open(ast->right->file, O_WRONLY | O_CREAT, 0664);
			error_catch(ast->fd_out == -1, "fail to open output file", root);
		}
		else if (ft_strncmp(ast->operator, ">>", 2) == 0)
		{
			ast->fd_out = open(ast->right->file, O_WRONLY | O_APPEND);
			if (ast->fd_out == -1)
				ast->fd_out = open(ast->right->file, O_WRONLY | O_CREAT, 0664);
			error_catch(ast->fd_out == -1, "fail to open output file", root);
		}
		else if (ft_strncmp(ast->operator, "<", 2) == 0)
		{
			ast->fd_in = open(ast->left->file, O_RDONLY);
			error_catch(ast->fd_in == -1, "fail to open input file", root);
		}
	}
}

void	close_fd(t_ast *ast, t_root *root)
{
	if (ast->type == _OPERATOR)
	{
		if (ft_strncmp(ast->operator, "|", 2) == 0
			|| ft_strncmp(ast->operator, "<<", 3) == 0)
		{
			close(ast->fd_in);
			close(ast->fd_out);
		}
		else if (ft_strncmp(ast->operator, ">", 2) == 0
			|| ft_strncmp(ast->operator, ">>", 3) == 0)
			close(ast->fd_out);
		else if (ft_strncmp(ast->operator, "<", 2) == 0)
			close(ast->fd_in);
	}
}

void	scan_ast(void (*fct)(t_ast *, t_root *), t_ast *ast, t_root *root)
{
	fct(ast, root);
	if (ast->left)
		scan_ast(fct, ast->left, root);
	if (ast->right)
		scan_ast(fct, ast->right, root);
}

void	ast_set_index(t_ast *ast)
{
	static int	index;

	ast->index = index;
	index++;
	if (ast->left)
		ast_set_index(ast->left);
	if (ast->right)
		ast_set_index(ast->right);
}

t_ast	*search_index(t_ast *ast, int index)
{
	static t_ast *ast_return;

	if (ast->index == index)
		ast_return = ast;
	if (ast->left)
		search_index(ast->left, index);
	if (ast->right)
		search_index(ast->right, index);
	return (ast_return);
}

int	read_heredoc_pipe(t_ast *ast, int heredoc_pipe[2])
{
	char	*line;

	while (1)
	{
		line = readline("pipe heredoc>");
		// check line not NULL
		if (!ft_strncmp(line, ast->limiter, ft_strlen(ast->limiter) + 1))
			break ;
		ft_putstr_fd(line, heredoc_pipe[1]);
		ft_putstr_fd("\n", heredoc_pipe[1]);
		free(line);
		line = NULL;
	}
	free(line);
	close(heredoc_pipe[1]);
	return (heredoc_pipe[0]);
}

void	exec_all_cmd(t_ast *ast, t_root *root)
{
	t_ast *ast_output;
	t_ast *ast_input;
	t_ast *ast_input_stop;

	if (ast->type == _CMD)
	{
		ast_output = search_index(root->ast_start, ast->index + 1)->parent;
		ast_input_stop = ast_output;
		while (1)
		{
			ast_input = ast->parent;
			printf("[%d] [%d]\n", ast_input->fd_in, ast_output->fd_out);
			if (ast_input->fd_in == 0 || ast_input->fd_out == 1)
				exec_cmd(ast, ast_input->fd_in, ast_output->fd_out, root);
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
