#include "libft.h"

int		ft_strlastchr(const char *s, int c)
{
	int a;

	a = ft_strlen(s);
	while (a >= 0)
	{
		if (s[a] == c)
			return (a);
		a--;
	}
	return (0);
}
