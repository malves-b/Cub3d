#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


char	*clean_rgb_string(const char *input)
{
	int		i = 0, j = 0, count = 0;
	const char	*tmp;
	char	*output;

	// Pular até o primeiro dígito
	while (input[i] && !ft_isdigit(input[i]))
		i++;
	tmp = &input[i];

	// Contar caracteres não espaços
	while (tmp[j])
	{
		if (tmp[j] != ' ')
			count++;
		j++;
	}

	output = malloc(count + 1); // aloca apenas o necessário
	if (!output)
		return (NULL);

	j = 0;
	while (*tmp)
	{
		if (*tmp != ' ')
			output[j++] = *tmp;
		tmp++;
	}
	output[j] = '\0';
	return (output);
}

int	main(void)
{
	const char *str = "F     25      5,     255,255";
	char *cleaned = clean_rgb_string(str);

	if (!cleaned)
	{
		printf("Erro ao alocar memória\n");
		return (1);
	}

	printf("Original: \"%s\"\n", str);
	printf("Limpa:    \"%s\"\n", cleaned);

	free(cleaned);
	return (0);
}