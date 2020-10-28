/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 14:17:45 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			overlap(void *d, void *s, size_t l)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	d1 = (unsigned char *)d;
	s1 = (unsigned char *)s;
	i = 0;
	while (i < l)
	{
		if (d1 == (s1 + i))
			return (1);
		else if ((d1 + i) == s1)
			return (0);
		i++;
	}
	return (0);
}

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if ((overlap(dst1, src1, len)) == 1)
	{
		i = len - 1;
		while (i >= 0)
		{
			dst1[i] = src1[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)(i) < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst1);
}
