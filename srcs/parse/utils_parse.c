#include "../../includes/cub.h"

void print_map(char **file)
{
	int i = 0;

	while (file[i])
	{
		printf("%s", file[i]);
		i++;
	}
}