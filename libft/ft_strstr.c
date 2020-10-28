/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:06:17 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0')
		{
			j++;
			k++;
		}
		if (haystack[k] != needle[j] && needle[j] != '\0')
		{
			i++;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return ((char *)&haystack[i]);
	return (NULL);
}
