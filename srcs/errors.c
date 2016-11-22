/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:55:49 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/18 16:11:15 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** used to print usage or error and exit the app.
*/

void			dp_error(int c)
{
	if (c == 1)
		ft_putstr_fd(ERR1, 1);
	else if (c == 2)
		ft_putstr_fd(ERR2, 1);
	exit(1);
}
