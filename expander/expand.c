/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:19 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/20 17:22:12 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * get_env_value will take a key and return the value if it exist in the env
 * 
*/

char	*get_env_value(t_shell *shell, char *key)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		if (ft_strncmp(key, env->content[0], ft_strlen(key)) == 0)
		{
			if (ft_strlen(key) == ft_strlen(env->content[0]))
				return (ft_strdup(env->content[1]));
		}
		env = env->next;
	}
	return (NULL);
}
// handle_sg_quotes(&i, str, &new);

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
		printf("expansion failed\n");
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

void	handle_db_quotes(int *i, char *str, t_char **new, t_shell *shell)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (str[*i] == '"')
		{
			*i = *i + 1;
			return ;
		}
		else if (str[*i] == '$')
			handle_dollar(i, str, new, shell);
		else
			handle_simple_char(i, str, new);
	}
}

void	handle_sg_quotes(int *i, char *str, t_char **new)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			*i = *i + 1;
			return ;
		}
		else
			handle_simple_char(i, str, new);
	}
}

void	handle_simple_char(int *i, char *str, t_char **new)
{
	t_char	*node;

	node = char_new(str[*i]);
	char_add_back(new, node);
	*i = *i + 1;
}

void	handle_dollar(int *i, char *str, t_char **new, t_shell *shell)
{
	char	tmp[100];
	int		start;
	char	*to_expand;

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
	{
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
}

void	handle_double_dollar(int *i, t_char **new)
{
	int		pid;
	char	*pid_c;

	*i = *i + 2;
	pid = getpid();
	pid_c = ft_itoa(pid);
	extract_tmp(pid_c, new);
	free(pid_c);
}

void	handle_exit_code(int *i, t_char **new, t_shell *shell)
{
	char	*exit_code;

	*i = *i + 2;
	exit_code = ft_itoa(shell->exit_code);
	extract_tmp(exit_code, new);
	free(exit_code);
}

void	init_tmp(char *tmp, int start, int index, char *str)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		tmp[i] = '\0';
		i++;
	}
	i = 0;
	while (start <= index)
	{
		tmp[i] = str[start];
		i++;
		start++;
	}
}

void	extract_tmp(char *tmp, t_char **new)
{
	int		i;
	t_char	*node;

	if (!tmp || tmp[0] == '\0' || !new)
		return ;
	i = 0;
	while (tmp[i])
	{
		node = char_new(tmp[i]);
		char_add_back(new, node);
		i++;
	}
}
char	*charlst_to_str(t_char **new)
{
	int		size;
	char	*expanded;
	t_char	*index;

	if (!new || !*new)
		return (NULL);
	size = get_t_char_length(new) + 1;
	expanded = malloc(sizeof(char) * size);
	if (!expanded)
		return (NULL);
	size = 0;
	while (*new)
	{
		index = *new;
		*new = (*new)->next;
		expanded[size] = index->c;
		index->next = NULL;
		free(index);
		size++;
	}
	expanded[size] = '\0';
	return (expanded);
}

int		get_t_char_length(t_char **new)
{
	int		i;
	t_char	*index;

	if (!new || *new == NULL)
		return (0);
	index = *new;
	i = 0;
	while (index)
	{
		index = index->next;
		i++;
	}
	return (i);
}

int	stop_crawling(int c)
{
	if (ft_isspace(c) == 1 || (c >= 32 && c <= 47) || (c >= 58 && c <= 64) \
		|| (c > 90 && c < 97) || (c > 122 && c < 127) || c == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
// 	char	tmp[100];
// 	int		nb = 9;
// 	char	str[50] = "0123456789";
// 	int		start = 0;
// 	int		*i;
// 	t_char	*new;
// 	char	*test;

// 	new = NULL;
// 	i = &nb;
// 	init_tmp(tmp, start, *i - 1, str);
// 	printf("init done %s \n",tmp);
// 	extract_tmp(tmp, &new);
// 	printf("after extraction\n");
// 	print_c(new);
// 	test = charlst_to_str(&new);
// 	printf("lst to str : %s\n",test);
// 	free(test);
// 	system("leaks exec");
// 	return (0);
// }
