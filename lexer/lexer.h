/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/27 17:34:44 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

t_token			*tokenize(char *input);
void			traverse(char *input, t_token **tokens);
void			get_word(char *input, int *i, int *start, t_token **tokens);
void			get_tokens(char *input, int *i, int *start, t_token **tokens);
void			skip_quote_token(char *input, int *i);
void			remove_upfront_spaces(char *str, int *i, int *start);
int				is_token(char *str);
t_token_type	token_type(char *str);
int				is_quote(char c);

#endif