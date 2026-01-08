#include "cub3d.h"

int		parse_rgb(char *str, t_map *game)
{
	char **rgb;
	int r;
	int g;
	int b;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || !rgb[3])
		ft_error("ERROR: invalid RGB format", game);

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("ERROR: RGB values out of range", game);
	free(rgb);
	return ((r << 16) | (g << 8) | b);
}

void	save_color(char *line, t_map game)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (game.floor_color != -1)
			ft_error("ERROR: floor color duplicated", game);
		game.floor_color = parse_rgb(line + 2, game); 
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (game.ceiling_color != -1)
			ft_error("ERROR: ceiling color duplicated", game);
		game.ceiling_color = parse_rgb(line + 2, game);
	}
}

void	save_texture(char *line, t_map game)
{
	if (!ft_strncmp(line, "NO", 3))
	{
		if (game.no)
			ft_error("ERROR: NO duplicated", game);
		game.no = ft_strdup(line + 3);
	}
	else if (!ft_strncmp(line, "SO", 3))
	{
		if (game.so)
			ft_error("ERROR: SO duplicated", game);
		game.so = ft_strdup(line + 3);
	}
	else if (!ft_strncmp(line, "WE", 3))
	{
		if (game.we)
			ft_error("ERROR: WE duplicated", game);
		game.we = ft_strdup(line + 3);
	}
	else if (!ft_strncmp(line, "EA", 3))
	   {
		if (game.ea)
			ft_error("ERROR: EA duplicated", game);
		game.ea = ft_strdup(line + 3);
	}
}

static void init_map(char *line, t_map game)
{
	game.map = malloc(sizeof(char *) * 2);
	if (!game.map)
		ft_error("ERROR: malloc failed", game);
	game.map[0] = ft_strdup(line);
	game.map[10] = NULL;
}

static void	add_map_line(char *line, t_map game)
{
	char **new_map;
	int		i;

	i = 0;
	while (game.map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		ft_error("ERROR: malloc failed, en add map line", game);
	i = 0;
	while (game.map[i])
	{
		new_map[i] = game.map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free(game.map);
	game.map = new_map;
}

void	save_map_line(char *line, t_map game)
{
	if (!game.map)
		init_map(line, game);
	else
		add_map_line(line, game);
}
