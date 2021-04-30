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
int		ft_widht(char *tags, va_list ap);
int		ft_precision(char *tags, va_list ap, int *is_precision_define);
char	ft_flag(char *tags, int *tag, int is_precision_define);

void	manage_specifier(t_list **output, int *tag, va_list ap);
void	case_diuxX(t_list **output, char specifier, long long value);
void	manage_precision(t_list **output, int *tag, int is_precision_define);
void	manage_widht(t_list **output, int *tag);

void	ft_itol(t_list **output, long long n, char *base);
void	ft_stol(t_list **output, char *str);
void	ft_ultol(t_list **output, unsigned long n, char *base);

#endif