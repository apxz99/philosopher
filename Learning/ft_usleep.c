# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t	milliseconds)
{
	int	error;
	size_t	start;

	error = 0;
	start = get_current_time();
	while(get_current_time() - start < milliseconds && error == 0)
		error = usleep(10000);
	return (error);
}

int	main(void)
{
	int	i = 0;

	while(i++ < 5)
	{
		printf("%zu\n", get_current_time());
		printf("%d\n", ft_usleep(1000));
	}
}