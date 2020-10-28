/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew_un.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 14:10:34 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned char		*ft_strnew_un(size_t size)
{
	size_t			i;
	unsigned char	*result;

	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	result[i] = '\0';
	return (result);
}
