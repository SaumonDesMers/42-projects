#include "minishell.h"

void	ft_list(t_list *lst, char *str, char *sym, t_list *next, t_list *prev)
{
	lst->str = str;
	lst->sym = sym;
	lst->next = next;
	lst->prev = prev;
}

int	main(int ac, char **av, char **env)
{
	t_root	root;
	t_list	lst_1;
	t_list	lst_2;
	t_list	lst_3;

	root.shell_env = env;

	ft_list(&lst_1, "/bin/ls", "|", &lst_2, NULL);
	ft_list(&lst_2, "/usr/bin/grep ft", "<<", &lst_3, &lst_1);
	ft_list(&lst_3, "file", NULL, NULL, &lst_2);
	open_and_malloc(&lst_1, &root);
	exec_all_cmd(&lst_1, &root);
	free_root(&root);
	return(0);
}