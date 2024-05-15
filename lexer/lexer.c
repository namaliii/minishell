/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:02:28 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 11:39:52 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
* tokenize - will take an input string and convert it to 
* a linked list of tokens based on type < > << >> | word
*/

t_token	*tokenize(char *input)
{
	t_token	*tokens;

	tokens = NULL;
	if (check_quotes(input) == 1)
		return (NULL);
	traverse(input, &tokens);
	return (tokens);
}

/**
 * traverse - will remove upfront spaces and then start
 * creating the list based on tokens , it also skip quotes
 * and split based on space or token 
*/

void	traverse(char *input, t_token **tokens)
{
	int	i;
	int	start;

	i = 0;
	remove_upfront_spaces(input, &i, &start);
	start = i;
	while (input[i])
	{
		if (is_quote(input[i]) == 1)
		{
			skip_quote_token(input, &i);
		}
		else if (is_token(input + i) > 0)
			get_tokens(input, &i, &start, tokens);
		else if (ft_isspace(input[i]) == 1)
		{
			get_word(input, &i, &start, tokens);
			remove_upfront_spaces(input, &i, &start);
		}
		else
			i++;
	}
	get_word(input, &i, &start, tokens);
}

/**
 * get_word- after encoutring a token , we need to save
 * the chars already read in the buffer and then save the token 
 * get word will get the already read chars and put them in the list
 * and also update the index i and the start position 
*/

void	get_word(char *input, int *i, int *start, t_token **tokens)
{
	int		size;
	t_token	*new_token;
	char	*str;

	if (*i == *start)
		return ;
	size = (*i - 1) - *start + 2;
	str = malloc(sizeof(char) * size);
	ft_strlcpy(str, (const char *)(input + *start), size);
	new_token = token_new(str, WORD);
	token_add_back(tokens, new_token);
	*start = *i;
}
/**
 * get_tokens will copy the previous read chars from start until i
 * so i right now is representing a token , after copying the word
 * it will also create a new node get the token type and add it to 
 * the list 
*/

void	get_tokens(char *input, int *i, int *start, t_token **tokens)
{
	int				size;
	t_token			*new_token;
	char			*str;
	t_token_type	type;

	get_word(input, i, start, tokens);
	size = is_token(input + (*i)) + 1;
	str = malloc(sizeof(char) * size);
	ft_strlcpy(str, (const char *)(input + *start), size);
	type = token_type(str);
	new_token = token_new(str, type);
	token_add_back(tokens, new_token);
	*i = *i + size - 1;
	*start = *i;
}

