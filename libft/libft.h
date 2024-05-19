/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:12 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/18 17:19:49 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../minishell.h"

int				ft_isspace(char c);
char			**ft_split(char const *str, char c);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t destsize);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t count, size_t size);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
char			*ft_itoa(int n);

#endif