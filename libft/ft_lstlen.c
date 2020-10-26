/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 14:26:12 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_lstlen(t_list *lst)
{
	t_list	*temp;
	int		len;

	temp = lst;
	len = 0;
	if (temp == NULL)
		return (len);
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
