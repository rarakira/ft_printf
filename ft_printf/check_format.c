/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:30:55 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 12:31:44 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char *fspec)
{
	if (fspec[ft_strlen(fspec) - 1] == 'd')
		return (1);
	if (fspec[ft_strlen(fspec) - 1] == 's')
		return (2);
	if (fspec[ft_strlen(fspec) - 1] == 'c')
		return (3);
	return (0);
}
