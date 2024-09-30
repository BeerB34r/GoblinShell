#include "function_definitions.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_readline(void)
{
	char	*output;
	char	c;
	int		status;

	output = NULL;
	status = 1;
	while (status > 0)
	{
		status = read(0, &c, 1);
		if (c == '\n')
			break ;
		output = ft_acatchar(output, c);
	}
	return (output);
}

// concatenates character to malloced string
char	*ft_acatchar(char *src, char c)
{
	char	*dest;
	int	i;

	dest = (char *)malloc(ft_strlen(src) + 2);
	if (!dest)
		ft_putstr("dest does not exist");
	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = c;
	dest[i] = '\0';
	free(src);
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

// haystack must be null-terminated
int	ft_strscontain(const char *needle, const char **haystack)
{
	int	i;

	i = -1;
	while (haystack[++i])
	{
		if (ft_strcmp(needle, haystack[i]) == 0)
			return (i);
	}
	return (-1);
}

int	ft_strcontain(const char *str, char c)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int	ft_strcpy(const char *src, char *dest)
{
	int	i;

	i = -1;
	while (src && src[++i])
		dest[i] = src[i];
	return (i);
}

int	ft_strcmp(const char *a, const char *b)
{
	int	result;

	result = 0;
	while (*a || *b)
	{
		result = *a++ - *b++;
		if (result)
			break ;
	}
	return (result);
}
