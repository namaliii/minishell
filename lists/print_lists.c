/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:31:37 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 11:56:16 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	print_nodes(t_node *s_cmd)
// {
// 	t_node	*index;

// 	index = s_cmd;
// 	while (index)
// 	{
// 		printf("------- new node %p ------\n", index);
// 		printf("command list : \n");
// 		print_char(index->cmd);
// 		printf("files list : \n");
// 		print_tokens(index->files);
// 		index = index->next;
// 	}
// }

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
		printf("%s\n",index->content);
		index = index->next;
	}
}

// void	print_char(char **str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str || !(*str))
// 	{
// 		printf("nothing found \n");
// 		return ;
// 	}
// 	while (str[i])
// 	{
// 		if (i == 0)
// 			printf("cmd : %s\n",str[i]);
// 		else
// 			printf("arg : %s\n",str[i]);
// 		i++;
// 	}
// }
