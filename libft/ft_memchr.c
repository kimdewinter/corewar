/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 15:05:42 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*my_s;
	unsigned char	my_c;
	unsigned char	*found;
	size_t			i;

	my_s = (unsigned char *)s;
	my_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (my_c == *my_s)
		{
			found = my_s;
			return (found);
		}
		else
		{
			my_s++;
			i++;
		}
	}
	my_s = NULL;
	return (my_s);
}
