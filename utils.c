#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)(n * (-1));
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

u_int64_t	get_my_time()
{
	struct timeval		tv;
	int					get_time;

	get_time = gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	print_and_return(char *str, int ret)
{
	printf("%s\n", str);
	return (ret);
}

int	ft_free(t_philo **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (1);
}

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		positive;

	i = 0;
	result = 0;
	positive = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
	(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		positive = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (((result > 2147483647) && positive) ||
		((result > 2147483648) && !positive))
			return (-1);
		i++;
	}
	if (positive == 0)
		result = result * (-1);
	return ((int)result);
}
