#include "../../includes/cub.h"

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

void	ft_itoa_hex(t_parse *parse, char **dest_color)
{
	int		len;
	char	*str_color = NULL;

	if(str_color != NULL)
	{
		free(*dest_color);
	 	*dest_color = NULL;
	}
	len = ft_count_hex(parse->r);
	len += ft_count_hex(parse->g);
	len += ft_count_hex(parse->b);
	str_color = malloc(sizeof(char) * (len + 1));
	number_to_hex(parse->r, str_color, 0); // r → positions 0,1
	number_to_hex(parse->g, str_color, 2); // g → positions 2,3
	number_to_hex(parse->b, str_color, 4); // b → positions 4,5
	str_color[6] = '\0';
	*dest_color = str_color;
	
}