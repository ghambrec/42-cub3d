#include "cub3d.h"

int	is_texture_line(char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	ft_atoi_rgb(const char *str)
{
	int			i;
	int			result;

	if (!str || !str[0])
		return (-1);
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' || !ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result > 255)
			return (-1);
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (-1);
	return (result);
}

uint32_t	parse_color(char *line, t_game *game)
{
	char		**rgb;
	int			r;
	int			g;
	int			b;
	uint32_t	color;

	line += 2;
	while (*line == ' ' || *line == '\t')
		line++;
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		if (rgb)
			ft_str2d_free(rgb);
		exit_failure(game, "Not enough rgb values");
	}
	r = ft_atoi_rgb(rgb[0]);
	g = ft_atoi_rgb(rgb[1]);
	b = ft_atoi_rgb(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
	{
		ft_str2d_free(rgb);
		exit_failure(game, "Wrong rgb value");
	}
	color = (r << 16) | (g << 8) | b;
	ft_str2d_free(rgb);
	return (color);
}
