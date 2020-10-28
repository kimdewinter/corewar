/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:23:52 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*s1;
	int		i;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	while (s1[i] != c1 && s1[i] != '\0')
		i++;
	if (s1[i] == c)
		return (&s1[i]);
	else
		return (NULL);
}
