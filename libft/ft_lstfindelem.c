/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfindelem.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 18:07:57 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:53 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_lstfindelem(t_list *lst, t_list *search_node)
{
	t_list	*temp;
	int		index;

	temp = lst;
	if (temp == NULL)
		return (0);
	index = 0;
	while (temp != NULL && temp != search_node)
	{
		index++;
		temp = temp->next;
	}
	if (temp != NULL)
		return (index);
	else
		return (0);
}
