void	ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar_fd(str[i++], fd);
}

void	ft_putstr_color(char *color, char *str, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}
