/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 13:22:37 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:58:52 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr_node;
	t_list	*next_node;

	curr_node = *alst;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		del(curr_node->content, curr_node->content_size);
		free(curr_node);
		curr_node = next_node;
	}
	*alst = NULL;
}
