/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:36:50 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 14:02:07 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libftprintf/libftprintf.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_ptr
{
	void	*wndow;
	void	*mlx;
	int		width;
	int		height;
	char	**map;
	int		player_count;
	int		hp_len;
	int		x;
	int		y;
	int		i;
}	t_ptr;

typedef struct s_image
{
	int		fd;
	int		width;
	int		height;
	void	*player;
	void	*sea;
	void	*stone;
	void	*out;
	void	*obj;
	void	*img_ptr;
	int		count;
	int		x;
	int		y;
}	t_image;

typedef struct s_bigdata
{
	int		x;
	int		y;
	t_ptr	ptr;
	t_image	image;
}	t_bigdata;

typedef struct s_mapcheck
{
	int		x;
	int		y;
	int		i;
	int		player;
	int		exit_game;
	int		collect;
	int		pass;
	int		count_pass;
	char	*cross_pass;
	char	*from_pass;
	int		*savex;
	int		*savey;
}	t_mapcheck;

typedef struct s_putmap
{
	int		fd;
	int		read;
	char	*buffer;
	int		x;
	int		y;
}	t_putmap;

// Cas d'erreurs
t_bool	line_one(t_bigdata *data, t_putmap *lenmap);
t_bool	middle_lines(t_bigdata *data, t_putmap *lenmap);
t_bool	is_toomuch(t_bigdata *data, t_putmap *lenmap);
t_bool	last_line(t_bigdata *data, t_putmap *lenmap);
t_bool	last_toomuch(t_bigdata *data, t_putmap *lenmap);
t_bool	is_long_map(t_bigdata *data, char *ber);
t_bool	init_long(t_putmap *lenmap, char *ber);
void	free_longmap(t_putmap *lenmap);

t_bool	is_goodfile(char *ber);
t_bool	is_goodext(char *ber);
int		end_filename(char *ber);
void	error_files(t_bigdata *data, char *ber);

t_bool	forest(t_mapcheck *map, t_putmap *readmap, t_bigdata *data);
t_bool	is_onething(t_bigdata *data, char *ber);
t_bool	init_things(t_bigdata *data, t_putmap *readmap, t_mapcheck *map);
void	free_things(t_putmap *readmap);
void	error_cases(t_bigdata *data, char *map);

void	count_error(t_bigdata *data, t_putmap *map);

//Parsing
t_bool	is_right_pass(t_bigdata data, char *ber);
t_bool	is_objcollect(t_bigdata data, char *ber);
void	wheres_player(t_mapcheck *mappy, t_bigdata *data, char *ber);
t_bool	what_path(t_bigdata *data, t_mapcheck *mappy);
t_bool	what_path_obj(t_bigdata *data, t_mapcheck *mappy, int count_hp);
t_bool	nothing_here(t_bigdata *data, t_mapcheck *mappy, int count_hp);
void	look_down(t_mapcheck *mappy);
void	look_up(t_mapcheck *mappy);
void	look_right(t_mapcheck *mappy);
void	look_left(t_mapcheck *mappy);
void	none_look(t_mapcheck *mappy, t_bigdata *data);
void	count_pass(t_bigdata *data, t_mapcheck *mappy);
void	count_pass_obj(t_bigdata *data, t_mapcheck *mappy);
t_bool	is_coord(t_mapcheck *mappy, int x, int y);
int		is_obj(t_mapcheck *mappy, t_bigdata *data, int count_hp);

//Map concerns
void	put_img(t_bigdata *data);
void	img_create(t_bigdata *data);
char	**ft_maptab(char *readmap, t_bigdata *data);
char	*go_map(t_putmap *put, t_bigdata *data);

//Keymove
int		deal_key(int keycode, t_bigdata *data);
void	is_movingd(t_bigdata *data);
void	is_movingw(t_bigdata *data);
void	is_movinga(t_bigdata *data);
void	is_movings(t_bigdata *data);

//Helping Functions
void	find_player(t_bigdata *data);
void	replace_image(t_bigdata *data);
void	replace_imagebis(t_bigdata *data);
int		countmap_y(char	*mappy, t_bigdata *data);
int		countmap_x(char	*mappy, t_bigdata *data);
int		close_wndow(t_bigdata *data);
void	close_error(t_bigdata *data);

//Externes
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
char	*go_malloc(size_t size);
void	printmap(char **map, t_ptr *ptr);
void	free_fct(t_bigdata *data, t_mapcheck *mappy);
int		*malloc_int(size_t size);
int		ft_strlen(char *str);

#endif
