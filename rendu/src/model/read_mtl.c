#include "read_mtl.h"

static int	skip_line(FILE *fp)
{
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return (1);
	}

	return (1);
}

void	use_mtl(const char *name, FILE *fp, t_material *material)
{
	const char	*vector_str[] = {"Ka", "Kd", "Ks"};
	t_vector	*vector_tab[] = {&(material->Ka), &(material->Kd), &(material->Ks)};

	const char	*float_str[] = {"Ns", "Ni", "d", "Tr"};
	float 		*float_tab[] = {&(material->Ns), &(material->Ni),  &(material->d), &(material->d)};

	(void)material;

	// TODO : check open

	fseek(fp, 0, SEEK_SET);

	// TODO : find mtl
	(void)name;

 	// TODO : stop at newmtl or EOF

	char			*type;
	int				ret;
	unsigned int	i;

	while (fscanf(fp, "%ms", &type) != EOF) // read first word
	{
		if (!type)
			return ;

		// if (strcmp(type, "newmtl") == 0)
			// return ;
		i = 0;
		while (i < 3)
		{
			if (strcmp(type, vector_str[i]) == 0)
			{
				ret = fscanf(fp, "%f %f %f",
						&(((*vector_tab)[i])[0]),
						&(((*vector_tab)[i])[1]),
						&(((*vector_tab)[i])[2]))
					!= 3 ? 0 : 1;
				break ;
			}
			i++;
		}
		if (i == 3)
		{
			i = 0;
			while (i < 4)
			{
				if (strcmp(type, float_str[i]) == 0)
				{
					ret = fscanf(fp, "%f", float_tab[i]) != 1 ? 0 : 1;
					if (i == 3)
						material->d = 1 - material->d;
					break ;
				}
				i++;
			}
			if (i == 4)
			{
				if (strcmp(type, "illum") == 0)
					ret = fscanf(fp, "%i", &(material->illum)) != 1 ? 0 : 1;
			}
		}

		ret = skip_line(fp);

		free(type);
		type = NULL;

		if (!ret)
			return ;	
	}
}

void	open_mtl(const char *name, t_model *model)
{
	char	*path;
	size_t	len;

	len = strlen(model->res_folder) + strlen(name) + 1;
	if ((path = (char *)malloc(len)) == NULL)
		return ;
	memset(path, '\0', len);
	strcat(path, model->res_folder);
	strcat(path, name);
	model->mtl_fp = fopen(path, "r");
	free(path);
}