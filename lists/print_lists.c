/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:31:37 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/20 19:33:06 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_nodes(t_node *s_cmd)
{
	t_node	*index;

	if (!s_cmd)
	{
		printf("cmdlist not provided \n");
		exit(44);
	}
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

	if (lst == NULL)
	{
		return ;
	}
	index = lst;
	while (index)
	{
		// printf("token : %s\n", index->content);
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

