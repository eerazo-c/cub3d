//pseudocode

"220,100,0"
   
["220", "100", "0"]
   
int r = 220
int g = 100
int b = 0
  
comprobar 0–255
   
(r << 16) | (g << 8) | b


	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		ft_error
//ft_atoi
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error values out of range
	free_split(rgb);
	return ((r << 16) | (g << 8) | b);


funcion  ft_free   libera matrices  y char **x

segmentation fault  en map.c   save_map()    linea 104