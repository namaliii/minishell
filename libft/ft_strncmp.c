/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:35:40 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/05/15 13:04:42 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	nbs1;
	unsigned char	nbs2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		nbs1 = (unsigned char)s1[i];
		nbs2 = (unsigned char)s2[i];
		if (nbs1 != nbs2)
			return (nbs1 - nbs2);
		i++;
	}
	return (0);
}
