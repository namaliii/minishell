/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:57:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/05/16 15:44:06 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
