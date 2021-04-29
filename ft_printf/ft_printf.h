#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

int		is_specifier(char c, char *specifiers);
char	*take_tags(char *s);
int		pars_tags(char *tags, va_list ap);

char	ft_specifier(char *tags);
char	ft_flag(char *tags);
int		ft_widht(char *tags, va_list ap);
int		ft_precision(char *tags, va_list ap);

void	manage_specifier(t_list **output, char specifier, va_list ap);
void	manage_precision(t_list **output, int precision, char specifier);
void	manage_widht(t_list **output, char flag, int widht);

void	ft_itol(t_list **output, int n);

#endif