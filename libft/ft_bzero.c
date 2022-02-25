#include "libft.h"

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*cast_p;

	cast_p = (unsigned char *)p;
	ft_memset(p, '\0', n);
}

