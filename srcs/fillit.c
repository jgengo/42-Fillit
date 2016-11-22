/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:54:51 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/18 16:44:55 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** free the final map
*/

static void		free_map(t_game *game)
{
	int i;

	i = 0;
	if (game->map)
	{
		while (i < 4 * game->nb_pieces)
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
}

/*
** used to print the valid map
*/

void			put_map(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (j < game->size)
	{
		i = 0;
		while (i < game->size)
			ft_putchar(game->map[j][i++]);
		ft_putchar('\n');
		j++;
	}
}

/*
** push da piece back to the end of our pieces list
*/

void			pushback_piece(t_game *game, t_piece *piece)
{
	t_piece		*lst;

	lst = game->pieces;
	if (!lst)
	{
		game->pieces = piece;
		game->nb_pieces++;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = piece;
	game->nb_pieces++;
}

/*
** main
*/

int				main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		dp_error(1);
		return (0);
	}
	if (init_game(&game, argv[1]))
	{
		solve(&game);
		put_map(&game);
		free_map(&game);
	}
	else
		dp_error(2);
	return (1);
}
