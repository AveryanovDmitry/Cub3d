/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:59:06 by hhoyl             #+#    #+#             */
/*   Updated: 2021/04/07 15:59:08 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "include/minilibx_mms/mlx.h"
# include "include/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "include/gnl/get_next_line.h"

# define SCALE 16
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define PI 3.14159265359

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}					t_rgb;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir;
	char			dir_symbol;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			start;
	double			end;
}					t_player;

/*
** структура данных mlx.
*/

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_print_sprite
{
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				d;
	int				tex_y;
	int				color;
}					t_print_sprite;

/*
** s_print_map:
** t_norm_print_map: структура для нормы.
** map_x в каком блоке карты мы находимся
** map_y в каком блоке карты мы находимся
** side_dist_x длина луча от текущей позиции до следующей стороны x или y
** side_dist_y длина луча от текущей позиции до следующей стороны x или y
** delta_dist_x длина луча от одной стороны x или y до следующей стороны x или y
** delta_dist_y длина луча от одной стороны x или y до следующей стороны x или y
** step_x в каком направлении делать шаг по оси x или y (+1 или -1)
** step_y в каком направлении делать шаг по  оси x или y (+1 или -1)
** hit там была стена?
** side Был ли удар по стене ПП или РЭБ?
** wall_x точное значение точки удара о стену,
** чтобы знать, какую x-координату текстуры мы должны использовать
** tex_x координата x текстуры
*/

typedef struct s_print_map
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_print_map;

/*
**res_w - цифры разрешения указанные в карте
**res_h - цифры разрешения указанные в карте
** *sp_x - массив координат х для спрайтов
** *sp_y - массив координат у для спрайтов
*/

typedef struct s_all
{
	int				res_w;
	int				res_h;
	char			*nor_tex;
	char			*sou_tex;
	char			*wes_tex;
	char			*eas_tex;
	char			*spr_tex;
	int				floore_flag;
	int				ceilling_flag;
	char			**map;
	char			*player_pos;
	int				player_x;
	int				player_y;
	int				size_map;
	int				count_sprite;
	t_rgb			floor;
	t_rgb			ceiling;
	void			*mlx;
	void			*mlx_win;
	t_data			t_n;
	t_data			t_s;
	t_data			t_w;
	t_data			t_e;
	t_data			t_spr;
	t_data			data;
	t_player		player;
	float			*sp_x;
	float			*sp_y;
	float			*dist;
	float			*close_sprite;
}					t_all;

void				check_space_in_wall(int size, t_all *kuba);
void				check_characters(int size, t_all *cub);
void				count_pars_data(t_all *cub);
int					message_error(char *str);
int					check_arg(int ac, char **av);
int					parsing_file(t_all *kuba, int fd, int count);
void				parser_map(int fd, t_all *cub);
void				check_space_in_rgb(char *line);
void				check_tab(char *line, t_all *cub);
void				check_ceiling(t_all *cub);
void				check_floor(t_all *cub);
void				check_resolution(t_all *cub);
void				get_floore(char *tmp, t_all *cub);
void				get_ceilling(char *tmp, t_all *cub);
void				runner_cub(t_all *cub, int argc);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				error(char *str, t_all *cub);
void				move_up(t_all *cub, double s);
void				move_back(t_all *cub, double s);
void				move_left(t_all *cub, double s);
void				move_right(t_all *cub, double s);
void				turn_right(t_all *cub, double r);
void				turn_left(t_all *cub, double r);
void				passing_texture(t_all *cub);
void				direction_player(t_all *cub);
void				sort_sprite(t_all *cub);
void				save_position_sprites(t_all *cub);
void				screenshot(t_all *cub);
void				free_lst_map(t_list **lst);
void				ray_mapxy(t_print_map *n, int *x, t_all *cub);
void				calc_step_start(t_print_map *n, t_all *cub);
void				check_hit(t_print_map *n, t_all *cub);
void				calc_other(t_print_map *n, t_all *cub, int *x);
void				draw_world(t_print_map *n, t_all *cub, int *x, int *y);
void				side_world_norm(t_print_map *n, t_all *cub,
						int *x, int *y);
void				print_sprite_norm(t_all *cub, t_print_sprite *s,
						int *y, int *stripe);
void				calc_sprite(t_all *cub, t_print_sprite *s, int *i);
int					close_win(t_all *cub);
int					counting_sprites(t_all *cub);
int					create_rgb(int r, int g, int b);
int					check_av_map(char *av);
int					check_av_save(char *av);
unsigned int		get_pixel(t_data *data, int x, int y);

#endif
