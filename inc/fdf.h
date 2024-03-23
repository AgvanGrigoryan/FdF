/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:12:54 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 12:53:08 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

# include <stdio.h>

# define MAX(a,b) (((a)>(b))?(a):(b))
# define MIN(a,b) (((a)<(b))?(a):(b))
# define TERNAR(Condition,arg1,arg2) ((Condition) ? (arg1) : (arg2))

# define ESC_KEYCODE 53
# define LEFT_ARROW_KEYCODE 123
# define RIGHT_ARROW_KEYCODE 124
# define BOTTOM_ARROW_KEYCODE 125
# define TOP_ARROW_KEYCODE 126
# define NUMPAD_PLUS_KEYCODE 69
# define NUMPAD_MINUS_KEYCODE 78
# define PLUS_KEYCODE 24
# define MINUS_KEYCODE 27
# define A_KEYCODE 0
# define S_KEYCODE 1
# define D_KEYCODE 2
# define W_KEYCODE 13

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	ORANGE = 0xFFA500,
	WHITE = 0xFCFCFC,
	GREY = 0x525252
};

# define SIDEBAR_WIDTH 200
# define LINE_COLOR 0xffb800

typedef struct s_ij
{
	int	i;
	int	j;
}	t_ij;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point p1;
	t_point p2;
}	t_line_cords;

typedef struct s_btn
{
	t_point	pos;
	t_point	size;
	void	(*action)(void *);
	char	*content;
}	t_btn;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr_end;
}	t_img;

typedef struct s_vars
{
	int		**map;
	int		**temp_map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point win_size;
	int		sidebar_width;
	int		x;
	int		y;
	char	*row;
	char	**row_splited;
	t_img	img;
	t_color start_color;
	t_color end_color;
	t_btn buttons[16];
	int		buttons_cnt;
	int		max_z;
	double	angle;
	double	z_rotate;
	double	x_rotate;
	double	y_rotate;
	int		motion_effect;
	int		z_zoom;
	int		total_steps;
	bool	top_view;
	bool	right_click;

	t_point start;
	int		field_size;
	int		progress_engine;
}	t_vars;


// Functions in ft_putstr_fd.c
void			ft_putstr_fd(char *s, int fd);

// Functions in ft_strlen.c
size_t			ft_strlen(const char *s);

// Functions in ft_strcmp.c
int				ft_strcmp(const char *s1, const char *s2);

// Functions in validation.c
int				validation(int argc, char *argv[], t_vars *vars);

// Functions in ft_split.c
char			**ft_split(char *str, char *charset);

// Functions in ft_atoi.c
int				ft_atoi(const char *str);

// Functions in ft_itoa.c
char			*ft_itoa(int n);

// fdf_utils1.c
void			free_array(char **array);
void			free_int_matrix(int **matrix);
int				ft_array_len(char **array);
int				*convert_line(t_vars *vars);
int				pfree(char *str, t_vars *vars, int return_value);
int				pfree_vars(char *str, t_vars *vars, int return_value);// sadfasfd

// fdf.c
void			draw_map(t_vars *vars, int i, int j, float t);
void			my_mlx_image_clear(t_img *data, t_vars *vars);
void			assign_p1_cords(t_line_cords *line, int i, int j, t_vars *vars);
void			assign_coordinates(t_ij p1ij, t_ij p2ij, t_line_cords *line, t_vars *vars);
void			show_sidebar_content(t_vars *vars);
// sidebar.c
void			draw_sidebar(t_vars *vars);
void			add_buttons(t_vars *vars);
void			check_button_pressed(int x, int y, t_vars *vars);
void			show_buttons_text(t_vars *vars);

// hooks.c
int				destroy_window(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);

// color_utils.c
unsigned int	trgb_to_uint(t_color *trgb, float factor);
unsigned int 	interpolate_color(t_color *start_color, t_color *end_color, float t);
unsigned int	get_pixel_color(t_img *data, int x, int y);
void			uint_to_trgb(t_color *trgb, unsigned int color);
void			set_color(t_color *dest_color, t_color copy_color);

// color_presets.c
void			color_preset_1(void *vars);
void			color_preset_2(void *vars);
void			color_preset_3(void *vars);
void			color_preset_4(void *vars);
void			color_preset_5(void *vars);

// button_actions.c
void			zoom_in(void *vars);
void			zoom_out(void *vars);
void			reverse_gradient(void *vars);
void			reset_map(void *void_vars);
void			motion_effect(void *void_vars);
void			z_zooming_up(void *void_vars);
void			z_zooming_down(void *void_vars);
void			move_start(int x_diff, int y_diff, t_vars *vars);

// button_actions2.c
void			change_rotate_x(float diff, t_vars *vars);
void			change_rotate_y(float diff, t_vars *vars);
void			change_rotate_z(float diff, t_vars *vars);
void			top_view(void *vars);
void			left_view(void *vars);
void			perspective_view(void *vars);

// rotate.c
void			isometric(t_line_cords *line, int z1, int z2, t_vars *vars);
void			rotate_x_axis(t_line_cords *line, int *z1, int *z2, t_vars *vars);
void			rotate_y_axis(t_line_cords *line, int *z1, int *z2, t_vars *vars);
void			rotate_z_axis(t_line_cords *line, t_vars *vars);
void			z_zooming(t_vars *vars, int *z1, int *z2);

// draw.c
void 			draw_line(t_point p0, t_point p1, t_vars *vars, unsigned int color);
void			draw_horizontal_lines(t_vars *vars);
void			draw_vertical_lines(t_vars *vars);
void			my_mlx_pixel_put(t_img *data, t_point p, unsigned int color);
void			draw(t_vars *vars);

#endif