#include "libft/libft.h"
#include "ft_printf.h"

int		is_specifier(char c, char *specifiers)
{
	int	i;

	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}

char	*take_tags(char *s)
{
	char	*dst;
	int 	i;

	i = 0;
	while (!is_specifier(s[i], "cspdiuxX%%"))
		i++;
	if(!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (!is_specifier(s[i], "cspdiuxX%%"))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = s[i];
	dst[++i] = 0;
	return (dst);
}
#include <stdio.h>
int		pars_tags(char *tags, va_list ap)
{
	int		nbchar;
	int		widht;
	int		precision;
	t_list	*output;
	t_list	*save;

	nbchar = 0;
	output = NULL;
	widht = ft_widht(tags, ap);
	precision = ft_precision(tags, ap);

	manage_specifier(&output, ft_specifier(tags), ap);
	manage_precision(&output, precision, ft_specifier(tags));
	manage_widht(&output, ft_flag(tags), widht);

	save = output;
	while (output)
	{
		printf("%s", (char*)output->content);
		output = output->next;
		nbchar++;
	}
	//printf("('%c') (%d) (.%d) (%c)", ft_flag(tags), widht, precision, ft_specifier(tags));
	ft_lstclear(&save, &free);
	return (nbchar);
}	