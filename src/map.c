#include "cub3d.h"

int		parse_rgb(char *str, t_map *game)
{
	char **rgb;
	int r;
	int g;
	int b;
	unsigned int color_hex;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		ft_error("ERROR: invalid RGB format", *game);

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("ERROR: RGB values out of range", *game);
	cub_free(rgb);
	color_hex = (((unsigned int)r << 16) | ((unsigned int)g << 8) | b);
	return (color_hex);
}

void	save_color(char *line, t_map *game)
{
	if (ft_strchr(line, 'F'))
	{
		if (game->floor_exist == 1)
			ft_error("ERROR: floor color duplicated", *game);
		game->floor_color = parse_rgb(line + 2, game);
		game->floor_exist = 1;
	}
	else if (ft_strchr(line, 'C'))
	{
		if (game->ceiling_exist == 1)
			ft_error("ERROR: ceiling color duplicated", *game);
		game->ceiling_color = parse_rgb(line + 2, game);
		game->ceiling_exist = 1;
	}
}

void	save_texture(char *line, t_map *game)
{
	if (ft_strchr(line, 'N'))
	{
		if (game->cardinal.no)
			ft_error("ERROR: NO duplicated", *game);
		game->cardinal.no = ft_strdup(line + 3);
	}
	else if (ft_strchr(line, 'S'))
	{
		if (game->cardinal.so)
			ft_error("ERROR: SO duplicated", *game);
		game->cardinal.so = ft_strdup(line + 3);
	}
	else if (ft_strchr(line, 'W'))
	{
		if (game->cardinal.we)
			ft_error("ERROR: WE duplicated", *game);
		game->cardinal.we = ft_strdup(line + 3);
	}
	else if (ft_strchr(line, 'E'))
	{
		if (game->cardinal.ea)
			ft_error("ERROR: EA duplicated", *game);
		game->cardinal.ea = ft_strdup(line + 3);
	}
}

/*
int lenn(char **s)
{
	int i;

	i = 0;
	while (s[i][0] != '\0')
		i++;
	return (i);
}
*/

static void	init_map(char *line, t_map *game)
{
	//ft_strlen(line);
	game->map = malloc(sizeof(char *) * ft_strlen(line));
	if (!game->map)
		ft_error("ERROR: malloc failed", *game);
	game->map[0] = ft_strdup(line);
	game->map[1] = NULL;
}

static void	add_map_line(char *line, t_map *game)
{
	char	**new_map;
	int		i;

	int aaa = ft_strlen(line);
	i = 0;
	/*while (game->map[i])
		i++;*/
	new_map = malloc(sizeof(char *) * (aaa));
	if (!new_map)
		ft_error("ERROR: malloc failed, en add map line", *game);
	while (game->map[i])
	{
		new_map[i] = game->map[i];
		i++;
	}
	new_map[i ] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free(game->map);
	game->map = new_map;
	free(new_map);
}

void	save_map_line(char *line, t_map *game)
{
	if (!game->map)
		init_map(line, game);
	else
		add_map_line(line, game);
}
