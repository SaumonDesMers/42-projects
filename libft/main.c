#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "libft.h"

int        main(void)
{
    char *s1 = "  \t \t \n   \n\n\n\t";
	char *ret = ft_strtrim(s1, " \n\t");

    //printf("%s\n", ret);
    return (0);
}