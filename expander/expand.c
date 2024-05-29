/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:19 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/29 17:26:37 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand(char *str, t_shell *shell)
{
	t_char	*new;
	char	*expanded;
	int		i;

	i = 0;
	new = NULL;
	if (!str || *str == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"')
			handle_db_quotes(&i, str, &new, shell);
		else if (str[i] == '\'')
			handle_sg_quotes(&i, str, &new);
		else if (str[i] == '$')
			handle_dollar(&i, str, &new, shell);
		else
		{
			handle_simple_char(&i, str, &new);
		}
	}
	expanded = charlst_to_str(&new);
	return (expanded);
}

void	delete_expanded_node(t_token **node, t_shell *shell)
{
	t_token	*prev;
	t_token	*index;
	t_token	*next;

	if (shell->tokens == (*node))
		shell->tokens = (shell->tokens)->next;
	index = *node;
	prev = (*node)->prev;
	next = (*node)->next;
	(*node) = (*node)->next;
	index->next = NULL;
	index->prev = NULL;
	free(index->content);
	free(index);
	if (prev)
	{
		prev->next = next;
		if (next)
			next->prev = prev;
	}
	else
	{
		if (next)
			next->prev = NULL;
	}
}

void	expand_all(t_shell *shell)
{
	char	*expanded;
	t_token	*index;

	index = shell->tokens;
	if (!index)
	{
		return ;
	}
	while (index)
	{
		expanded = NULL;
		expanded = expand(index->content, shell);
		if (expanded == NULL)
		{
			delete_expanded_node(&index, shell);
		}
		else
		{
			free(index->content);
			index->content = expanded;
			index = index->next;
		}
	}
}

void	actually_expand(int *i, char *str, t_char **new, t_shell *shell)
{
	int		start;
	char	tmp[100];
	char	*to_expand;

	*i = *i + 1;
	start = *i;
	while (str[*i] && stop_crawling(str[*i]) == 0)
	{
		*i = *i + 1;
	}
	init_tmp(tmp, start, *i - 1, str);
	to_expand = get_env_value(shell, tmp);
	if (to_expand != NULL)
	{
		extract_tmp(to_expand, new);
		free(to_expand);
	}
}

void	handle_dollar(int *i, char *str, t_char **new, t_shell *shell)
{
	if (str[*i] == '$' && ft_isdigit(str[*i + 1]) == 1)
		*i = *i + 2;
	else if (str[*i] == '$' && str[*i + 1] == '$')
		handle_double_dollar(i, new);
	else if (str[*i] == '$' && str[*i + 1] == '?')
		handle_exit_code(i, new, shell);
	else if (str[*i] == '$' && ((str[*i + 1] == '\'') || (str[*i + 1] == '"')))
		*i = *i + 1;
	else if (str[*i] == '$' && stop_crawling(str[*i + 1]) == 1)
		handle_simple_char(i, str, new);
	else
		actually_expand(i, str, new, shell);
}
