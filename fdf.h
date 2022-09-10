/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:00:05 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/10 12:43:26 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define C_H 500
# define C_W 500

typedef struct s_mlx_var
{
	void	*mlx;
	void	*win;
}	t_mlx_var;

typedef struct s_vec_2d
{
	double	x;
	double	y;
}	t_vec_2d;

typedef struct s_vec_h
{
	double	x;
	double	y;
	double	z;
	double	h;
}	t_vec_h;

typedef struct s_vec_lst
{
	t_vec_h				v;
	int					is_end_line;
	struct s_vec_lst	*next;
}	t_vec_lst;

typedef struct s_grid
{
	t_vec_lst	*head;
	t_vec_lst	*back;
	int			n_row;
	int			n_col;
}	t_grid;

// parse_file.c
void	append_grid(t_grid *grid_ptr, char *line);
t_grid	parse_file(char *path);
void	handle_error(t_grid grid, char *msg);
void	free_grid(t_grid grid);

// draw_line.c
void	draw_line(t_vec_2d v0, t_vec_2d v1, int color);

// display_grid_loop.c
void	display_grid_loop(t_grid grid);
t_mlx_var	initialize(void);

#endif
