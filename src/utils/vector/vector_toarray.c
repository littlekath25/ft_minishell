/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_toarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 16:50:56 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 22:09:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vector.h"

char	**vector_tostrarray(t_vector *vect)
{
	char	**strs;
	int		i;

	strs = malloc((vect->nmemb + 1) * sizeof(char *) );
	if (!strs)
		exit(0);
	i = 0;
	while (i < vect->nmemb)
	{
		strs[i] = ft_strdup((char *)vector_getvalue(vect, i));
		if (!strs[i])
			exit(0);
		i++;
	}
	strs[i] = 0;
	return (strs);
}

// char	**vector_tostrarray(t_vector *vect)
// {
// 	char	**strs;
// 	int		len;
// 	int		i;
// 	char	*tmp;

// 	len = 0;
// 	i = 0;
// 	while (i < vect->nmemb)
// 	{
// 		tmp = vector_getvalue(vect, i);
// 		len += ft_strlen(tmp) + sizeof(char *) + 1;
// 		i++;
// 	}
// 	strs = malloc(len + sizeof(char *));
// 	if (!strs)
// 		exit(0);
// 	i = 0;
// 	len = 0;
// 	while (i < vect->nmemb)
// 	{
// 		tmp = vector_getvalue(vect, i);
// 		len += ft_strlcpy(strs + len, tmp, ft_strlen(tmp) + 1);
// 		i++;
// 	}
// 	return (strs);
// }
