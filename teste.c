#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

i
// int	main(void)
// {
// 	const char *str = "F     - -   25      5,     255,255";
// 	char *cleaned = clean_rgb_string(str);

// 	if (!cleaned)
// 	{
// 		printf("Erro ao alocar memória\n");
// 		return (1);
// 	}

// 	printf("Original: \"%s\"\n", str);
// 	printf("Limpa:    \"%s\"\n", cleaned);

// 	free(cleaned);
// 	return (0);
// }