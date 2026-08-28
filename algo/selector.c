#include "push_swap.h"

static int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_algo_flag(char *s)
{
	return (strcmp(s, "--simple") == 0 || strcmp(s, "--medium") == 0
		|| strcmp(s, "--complex") == 0 || strcmp(s, "--adaptive") == 0);
}

int	leading_flags(int argc, char **argv, int *bench, char **algo)
{
	int	n;

	*bench = 0;
	*algo = NULL;
	n = 0;
	if (argc > 1 && strcmp(argv[1], "--bench") == 0)
	{
		*bench = 1;
		n = 1;
		if (argc > 2 && is_algo_flag(argv[2]))
		{
			*algo = argv[2];
			n = 2;
		}
	}
	else if (argc > 1 && is_algo_flag(argv[1]))
	{
		*algo = argv[1];
		n = 1;
	}
	else if (argc > 1 && is_flag(argv[1]))
		ft_error_exit();
	return (n);
}

static void	run_selected(char *algo, t_stack **a, t_stack **b, int size,
		int *counts)
{
	if (algo && strcmp(algo, "--simple") == 0)
	{
		counts[11] = 4;
		ft_simple_algo(a, b, counts);
	}
	else if (algo && strcmp(algo, "--medium") == 0)
	{
		counts[11] = 5;
		medium_algo(a, b, size, counts);
	}
	else if (algo && strcmp(algo, "--complex") == 0)
	{
		counts[11] = 6;
		quick_sort_a(a, b, size, counts);
	}
	else
		ft_adaptive(a, b, size, counts);
}

void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b,
		int size)
{
	int		i;
	int		counts[12] = {0};
	int		bench;
	char	*algo;
	double	disorder;

	i = 1 + leading_flags(argc, argv, &bench, &algo);
	while (i < argc)
	{
		if (is_flag(argv[i]))
			ft_error_exit();
		i++;
	}
	disorder = 0.0;
	if (bench)
		disorder = ft_disorder(*a, size);
	run_selected(algo, a, b, size, counts);
	if (bench)
		print_bench(disorder, counts);
}
