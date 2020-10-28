/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:39:19 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;
	char	*s1;
	char	c1;
	int		len;

	i = 0;
	found = 0;
	len = 0;
	s1 = (char *)s;
	c1 = (char)c;
	while (s1[len] != '\0')
		len++;
	while (i <= len)
	{
		if (s1[i] == c1)
			found = &s1[i];
		i++;
	}
	if (found == 0)
		return (NULL);
	else
		return (found);
}
