/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:31:37 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/17 18:48:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_nodes(t_node *s_cmd)
{
	t_node	*index;

	index = s_cmd;
	while (index)
	{
		printf("------- new node %p ------\n", index);
		printf("command list : \n");
		print_char(index->cmd);
		printf("files list : \n");
		print_tokens(index->files);
		index = index->next;
	}
}

void	print_tokens(t_token *lst)
{
	t_token	*index;

	if (!lst)
	{
		printf("no list provided\n");
		return ;
	}
	index = lst;
	while (index)
	{
		printf("%s   %d\n",index->content, index->type);
		index = index->next;
	}
}

void	print_char(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
	{
		printf("nothing found \n");
		return ;
	}
	while (str[i])
	{
		if (i == 0)
			printf("cmd : %s\n",str[i]);
		else
			printf("arg : %s\n",str[i]);
		i++;
	}
}

void	print_c(t_char *lst)
{
	t_char	*index;

	if (!lst)
		return ;
	index = lst;
	while (index)
	{
		printf("%c\n", index->c);
		index = index->next;
	}
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


