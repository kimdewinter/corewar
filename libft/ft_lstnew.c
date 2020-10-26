/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 14:58:54 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*newnode;
	void	*temp;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	if (content == NULL)
	{
		newnode->content = NULL;
		newnode->content_size = 0;
	}
	else
	{
		temp = (void *)malloc(sizeof(void) * content_size);
		if (temp == NULL)
		{
			free(newnode);
			return (NULL);
		}
		ft_memcpy(temp, content, content_size);
		newnode->content = temp;
		newnode->content_size = content_size;
	}
	newnode->next = NULL;
	return (newnode);
}
