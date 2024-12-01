#ifndef D1_H
# define D1_H
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct	s_lists
{
	char	*input;
	int		*list_a;
	int		*list_b;
	int		len;
}				t_lists;

void	get_list_len(t_lists *lists);
void	parse(t_lists *lists);
void	free_double_pointer(char **str);
void	sort(int *list, int len);
void	free_memory(t_lists *lists);
int		get_similarity(t_lists *lists);
int		get_total_distance(t_lists *lists);

#endif