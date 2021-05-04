#include "include_lib.h"

void	set_input(t_root *root)
{
	int		i = 0;
	char	*str[10] =  {"1111111111",
						"1000100001",
						"1000100001",
						"1000000101",
						"1110100001",
						"1000000001",
						"1000101001",
						"1001000001",
						"1000000001",
						"1111111111"};

	root->win.widht = 1920;
	root->win.height = 1080;

	root->input.grid = malloc(sizeof(char*) * 10);
	while (i < 10)
	{
		root->input.grid[i] = malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		ft_strlcpy(root->input.grid[i], str[i], ft_strlen(str[i]) + 1);
		i++;
	}

	root->input.grid_widht = 10;
	root->input.grid_height = 10;
	//root->input.NO_img;
	//root->input.SO_img;
	//root->input.WE_img;
	//root->input.EA_img;
	//root->input.sprite_img;
	root->input.c_color = create_trgb(0,0,0,20);
	root->input.f_color = create_trgb(0,40,40,40);
}

void	free_grid(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->input.grid_height)
		free(root->input.grid[i++]);
	free(root->input.grid);
}