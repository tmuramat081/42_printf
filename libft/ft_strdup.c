#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src);
	p = (char *) malloc (sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}
