/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 12:09:15 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	while (haystack[i] != '\0' && needle[j] != '\0' && l < len)
	{
		while (haystack[i + j] == needle[j] && l < len && needle[j] != '\0')
		{
			j++;
			l++;
		}
		if (haystack[i + j] != needle[j] && needle[j] != '\0')
		{
			i++;
			j = 0;
			l = i;
		}
	}
	if ((needle[j] == '\0'))
		return ((char*)&haystack[i]);
	else
		return (NULL);
}
