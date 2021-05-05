/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:42:17 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:31:20 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
		i--;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}
