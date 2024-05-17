/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:07:13 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 17:29:08 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_char	*char_last(t_char *lst)
{
	t_char	*index;

	index = lst;
	if (lst == NULL)
		return (NULL);
	while (index->next != NULL)
		index = index->next;
	return (index);
}

void	char_add_back(t_char **lst, t_char *new)
{
	t_char	*index;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		index = char_last(*lst);
		index->next = new;
	}

}

t_char	*char_new(char content)
{
	t_char	*node;

	node = malloc(sizeof(t_char));
	if (node == NULL)
		return (NULL);
	node->c = content;
	return (node);
}
