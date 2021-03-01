/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:37:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/13 11:48:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPPERCASE_OFFSET 32

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - UPPERCASE_OFFSET);
	else
		return (c);
}
