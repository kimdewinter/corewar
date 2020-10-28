/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 13:53:55 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			l;

	l = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*c1 != '\0') && (*c2 != '\0') && (l < (n - 1)))
	{
		if (*c1 == *c2)
		{
			c1++;
			c2++;
			l++;
		}
		else
			return (*c1 - *c2);
	}
	return (*c1 - *c2);
}
