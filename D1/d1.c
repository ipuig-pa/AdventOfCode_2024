#include "d1.h"

void	get_list_len(t_lists *lists)
{
	int		fd;
	char	*line;

	fd = open(lists->input, 0);
	line = get_next_line(fd);
	if (!line)
		exit (1);
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		lists->len++;
	}
	close (fd);
}

void	parse(t_lists *lists)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	fd = open(lists->input, 0);
	line = get_next_line(fd);
	if (!line)
		exit (1);
	i = 0;
	while (line)
	{
		split = ft_split(line, ' ');
		if (!split)
		{
			free (line);
			exit (1);
		}
		lists->list_a[i] = ft_atoi(split[0]);
		lists->list_b[i] = ft_atoi(split[1]);
		free (line);
		free_double_pointer(split);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	sort(int *list, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		if (list[i] > list[i + 1])
		{
			temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
			if (i != 0)
				i = i - 1;
		}
		else
			i++;
	}
}

void	free_memory(t_lists *lists)
{
	if (lists->list_a)
		free(lists->list_a);
	if (lists->list_b)
		free(lists->list_b);
}

int	get_total_distance(t_lists *lists)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < lists->len)
	{
		res = res + abs(lists->list_a[i] - lists->list_b[i]);
		i++;
	}
	return (res);
}

int	get_similarity(t_lists *lists)
{
	int	a;
	int	b;
	int	count_appear;
	int	res;

	res = 0;
	a = 0;
	while (a < lists->len)
	{
		count_appear = 0;
		b = 0;
		while (b < lists->len)
		{
			if (lists->list_b[b] == lists->list_a[a])
				count_appear++;
			b++;
		}
		res = res + lists->list_a[a] * count_appear;
		a++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_lists	lists;
	int		total_distance;
	int		similarity;

	if (argc != 2)
		return (1);
	ft_memset(&lists, 0, sizeof(t_lists));
	lists.input = argv[1];
	get_list_len(&lists);
	lists.list_a = (int *)malloc(lists.len * sizeof(int));
	lists.list_b = (int *)malloc(lists.len * sizeof(int));
	parse(&lists);
	sort(lists.list_a, lists.len);
	sort(lists.list_b, lists.len);
	total_distance = get_total_distance(&lists);
	similarity = get_similarity(&lists);
	ft_printf("dist: %i\nsim: %i\n", total_distance, similarity);
	free_memory(&lists);
	return (0);
}
