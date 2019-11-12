#include "fillit.h"

int		main()
{
	int				fd;
	t_struct		*str;
	t_list_matrix	*stack;

	str = (t_struct *)ft_memalloc(sizeof(t_struct));
	create_list(&str->list, NULL);
	
		if ((fd = open("data", O_RDONLY)) < 0)
			return (-1);
		if (ft_read(fd, &str, &stack) < 0)
		{
			ft_putstr("error\n");
			return (-1);
		}
	return (0);
}
