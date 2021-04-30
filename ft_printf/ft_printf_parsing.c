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
	if(!(dst = malloc(sizeof(char) * (i + 2))))
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
	int		tag[4];
	int		is_precision_define;
	t_list	*output;
	t_list	*copy;

	nbchar = 0;
	output = NULL;
	is_precision_define = 0;
	tag[3] = ft_specifier(tags);
	tag[1] = ft_widht(tags, ap);
	tag[2] = ft_precision(tags, ap, &is_precision_define);
	tag[0] = ft_flag(tags, tag, is_precision_define);

	manage_specifier(&output, tag, ap);
	manage_precision(&output, tag, is_precision_define);
	manage_widht(&output, tag);

	copy = output;
	while (copy)
	{
		//printf("%s", (char*)copy->content);
		write(1, (char*)copy->content, 1);
		copy = copy->next;
		nbchar++;
	}

	//printf("{%c}{%d}{.%d}{%c}{%d}", tag[0], tag[1], tag[2], tag[3], is_precision_define);
	ft_lstclear(&output, &free);
	return (nbchar);
}	