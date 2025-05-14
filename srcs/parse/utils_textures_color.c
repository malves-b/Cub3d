#include "../../includes/cub.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int ft_count(const char *temp)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (temp[j])
	{
		if (temp[j] != ' ' && (temp[j] < 9 || temp[j] > 13))
			count++;
		j++;
	}
	return (count);

}

char	*clean_rgb_string(const char *input)
{
	int		i = 0;
	const char	*temp;
	char	*output;

	while (input[i] && !ft_isdigit(input[i]))
	{
		i++;
	}
	temp = &input[i];
	output = malloc(ft_count(temp) + 1); // aloca apenas o necessário
	if (!output)
		return (NULL);
	i = 0;
	while (*temp)
	{
		if (*temp != ' ' && (*temp < 9 || *temp > 13))
			output[i++] = *temp;
		temp++;
	}
	output[i] = '\0';
	return (output);
}


bool check_letters(char *str)
{
	int i = 0;
	//bool c_f = false;

	while (ft_isspace(str[i]))
	{
		printf("aquiiii");
		i++;
	}
	if(str[i] != 'C' && str[i] != 'F' )
		return (false);
	i++;
	while(str[i] != '\0')
	{
		if(!ft_isspace(str[i]) && !ft_isdigit(str[i]) && str[i] != ',')
			return (false);
		i++;
	}
	return (true);
}