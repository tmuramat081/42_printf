#include <stdio.h>

void	*ft_memchr(const void *buff, int ch, size_t n)
{
	unsigned char	*buff_cast;

	buff_cast = (unsigned char *)buff;
	while (n--)
	{
		if (*buff_cast == (unsigned char)ch)
			return ((void *)buff_cast);
		buff_cast++;
	}
	return (NULL);
}
