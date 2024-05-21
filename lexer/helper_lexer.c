/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:02:28 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/21 16:14:42 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * skip_quote_token will take an input and a position i
 * and will move i until it encounter the closing quotes 
*/

void	skip_quote_token(char *input, int *i)
{
	int	start;

	start = *i;
	*i = *i + 1;
	while (input[*i] && input[*i] != input[start])
		*i = *i + 1;
	*i = *i + 1;
}

/**
 * remove_upfront_spaces - will remove spaces by moving the cursor 
*/

void	remove_upfront_spaces(char *str, int *i, int *start)
{
	while (str[*i] && ft_isspace(str[*i]) == 1)
	{
		*i = *i + 1;
	}
	*start = *i;
}

/**
 * is_token - will check the current 2 positions of a string 
 * if they represent a token
*/

int	is_token(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (1);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (2);
	if (str[0] == '<')
		return (1);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (2);
	if (str[0] == '>')
		return (1);
	return (0);
}

/**
 * token_type - will check for the token type
*/

t_token_type	token_type(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (HEREDOC);
	if (str[0] == '<')
		return (INFILE);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (APPEND);
	if (str[0] == '>')
		return (OUTFILE);
	return (0);
}

/**
 * token_type - will check for the token type
*/

int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

// void	get_quote_token(char *input, int *i, int *start, t_token **tokens)
// {
// 	int		size;
// 	// char	*str;
// 	t_token	*new_token;

// 	// get_word(input, i, start, tokens);
// 	*i = *i + 1;
// 	while (input[*i] && input[*i] != input[*start])
// 		*i = *i + 1;
// 	// size = *i - *start + 2;
// 	// str = malloc(sizeof(char) * size);
// 	// ft_strlcpy(str, (const char *)(input + *start), size);
// 	// new_token = token_new(str, QUOTES);
// 	// token_add_back(tokens, new_token);
// 	*i = *i + 1;
// 	// *start = *i;
// }
