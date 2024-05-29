/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:07:13 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:49:41 by mfaoussi         ###   ########.fr       */
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
	node->next = NULL;
	return (node);
}

t_char	*str_to_charlst(char *str)
{
	t_char	*lst;
	t_char	*new;
	int		i;

	lst = NULL;
	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i])
	{
		new = char_new((char)str[i]);
		char_add_back(&lst, new);
		i++;
	}
	return (lst);
}
