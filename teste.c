#include <stdio.h>
#include <stdlib.h>

typedef struct s_parse
{
	int		r;
	int		g;
	int		b;
	char *hexa;
}	t_parse;


static int	ft_count_hex(unsigned int nbr)
{
	int	i = 0;

	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}


static void number_to_hex(int nbr, char *hexa, int start)
{
	char hex_digits[] = "0123456789abcdef";

	// First hex digit (most significant nibble)
	hexa[start] = hex_digits[nbr / 16];

	// Second hex digit (least significant nibble)
	hexa[start + 1] = hex_digits[nbr % 16];
}

char	*ft_utoa_hex(t_parse *parse)
{
	int		len;
	char	*temp;
	len = ft_count_hex(parse->r);
	len += ft_count_hex(parse->g);
	len += ft_count_hex(parse->b);
	parse->hexa = malloc(sizeof(char) * (len + 1));
	number_to_hex(parse->r, parse->hexa, 0); // r → positions 0,1
	number_to_hex(parse->g, parse->hexa, 2); // g → positions 2,3
	number_to_hex(parse->b, parse->hexa, 4); // b → positions 4,5
	parse->hexa[6] = '\0';
	return (parse->hexa);
	
}

// int main ()
// {
// 	t_parse *parse = malloc(sizeof(t_parse) * 1);
// 	parse->r = 0;
// 	parse->g = 0;
// 	parse->b = 0;

// 	printf("%s", ft_utoa_hex(parse));
// 	free(parse->hexa);
// 	free(parse);
//     return 0;
// }