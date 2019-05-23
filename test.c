#include <stdio.h>
#include "string.h"

int main(int ac, char **av)
{

	if (ac != 2)
		return (0);

	char	*path;
	path = av[1];

	FILE	*fp;
	fp = fopen(path, "r");
	if (!fp)
		return 1;

	int		i;
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		printf("(%zu) s = %s\n", strlen(s), s);
		if (strchr(s, '\n'))
		{
			printf("found a '\\n'\n");
			break;
		}
	}

	while (fgets(s, 1025, fp) != NULL)
	{
		printf("(%zu) s = %s\n", strlen(s), s);
		if (strchr(s, '\n'))
		{
			printf("found a '\\n'\n");
			break ;
		}
	}

	fclose(fp);

	return 0;
}