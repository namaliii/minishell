/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:06:06 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/22 17:06:59 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
