#include <stdio.h>
#include "../../../includes/vector.h"

void	print_items(t_vector *vect)
{
	int i = 0;
	printf("%d\n", vect->nmemb);
	while (i < vect->nmemb)
	{
		printf("%s\n", (char *)vector_getvalue(vect, i));
		i++;
	}
}

void	print_strings(char **strs)
{
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
}

int	main(void)
{
	t_vector	*vect;
	char		*str;
	char		*str1;
	char		*str2;

	str = ft_strdup("Hello");
	str1 = ft_strdup("Warlda");
	str2 = ft_strdup("Worldb");

	vect = vector_newptr();
	vector_add(vect, str);
	vector_add(vect, str1);
	vector_add(vect, str2);
	// print_items(vect);


	// vector_remove(vect, 1);
	// print_items(vect);


	// print_items(vect);


	// vector_remove(vect, vect->nmemb);
	// vector_remove(vect, vect->nmemb);
	// print_items(vect);

	printf("\n\n");

	char	**strs;
	strs = vector_tostrarray(vect);

	printf("Index: %d\n", vector_indexof(vect, "Warlda", 6));

	vector_clear(vect);
	vector_free(vect);
	free(strs);
}
