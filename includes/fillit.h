/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:04:19 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/18 16:47:10 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define CBLOCK '#'
# define CEMPTY '.'

# define ERR1 "usage: ./fillit source_file\n"
# define ERR2 "error\n"

typedef struct		s_coord
{
	int t;
	int r;
	int b;
	int l;
}					t_coord;

typedef struct		s_piece
{
	int				x;
	int				y;
	int				width;
	int				height;
	char			**map;
	char			letter;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_game
{
	t_piece		*pieces;
	int			nb_pieces;
	int			size;
	char		**map;
}					t_game;

void				put_map(t_game *game);
void				dp_error(int c);
int					parse_file(t_game *game, char *file);
int					init_game(t_game *game, char *file);
void				store_block(t_game *game, char *buf);
void				pushback_piece(t_game *game, t_piece *piece);
void				solve(t_game *game);
char				*buf_to_piece(char const *s, unsigned int start,
						size_t len, char l);

#endif
