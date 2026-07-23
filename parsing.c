#include "pushswap.h"

void	init_stack_a(int argc, char **argv, t_stack **stack_a)
{
	char	**split_args;
	int		i;
    int     j;
	long	num;

    i = 1;
	while (i < argc)
	{
        j = 0;
        if (!argv[i] || argv[i][0] == '\0' || check_spaces(argv[i]))
			ft_error(stack_a, NULL);
        split_args = ft_split(argv[i++], ' ');
	    if (!split_args)
		    ft_error(stack_a, NULL);
	while (split_args[j])
	{
		num = ft_atoi_strict(split_args[j], stack_a, split_args);
		ft_stack_add_back(stack_a, stack_new((int)num));
		j++;
	}
	free_string_array(split_args);
    }
    	check_duplicates(stack_a);
}