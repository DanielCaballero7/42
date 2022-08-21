int	ft_printf(char const *fmt, ...)
{
	int len;
	char	*c;
	va_list	list;
	long u;
	
	va_start(lista; fmt);
	c = fmt;
	len = 0;
	while (*c != '\0')
	{
		if (c != '%')
			len = ft_putfirstchar(c, len);
		else
		{
			c = ++fmt;
			if (c == 'c')
				len = ft_putchar(va_arg(list, char), len);
			else if (c == 's')
				len = ft_putstring(va_arg(list, char *), len);
			else if (c == 'p')
			{
				u = va_arg(list, (long) *);
				len = ft_putnum(u, len);
			}
			else if (c == 'd')
				len = ft_putdecimal(va_arg(list, int), len);
			else if (c == 'i')
				len = ft_putnum(va_arg(list, int), len);
			else if (c == 'u')
			{
				u = va_arg(list, int) * -1:
				len = ft_putnum(u, len);
			}
			else if (c == 'x')
				len = ft_puthex(va_arg(list, int), len, 0);
			else if (c == 'X')
				len = ft_puthex(va_arg(list, int), len, 1);
			else if (c == '%')
				len = ft_putchar('%', len);	
		}
	}
	
		return (len);
}

int	ft_putfirstchar(char *c, int len)
{
	write(1, &c, 1);
	len++;
	return(len);
}

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return(len);
}

int	ft_putstring(char *c, int len)
{
	while (*c != '\0')
	{
		len = ft_putfirstchar(c, len)
		c++;
	}
	return(len);
}

int	ft_putdecimal(int n, int len)
{
	int	charn;
	
	if (n < 0)
	{
		len = ft_putchar('-', len)
		n *= -1;
	}
	n = n + '0';
	len = ft_putchar((char) n, len);
	return (len);
}

int	ft_putnum(int n, int len)
{
	if (n < 0)
	char buf[12];
	char *p;
	
	buf[12] = '\0'
	p = &buf[11];
	{
		len = ft_putchar('-', len)
		n *= -1;
	}
	while (n != 0)
	{
		p-- = (n % 10) + '0';
		n /= 10;
	}
	p++;
	len = ft_putstring(p; len);
	return (len);
}

int	ft_puthex(long n, int len, int upper)
{
	int	prefix;
	char static	digs[32];
	char	buf[12];
	char *p;
	
	&buf[12] = '\0';
	p = buf[11];
	digs = "0123456789abcdef0123456789ABCDEF"
	if (upper == 1)
	{
		prefix = 16;
		len = ft_putstring("0x", len);
	}
	else
		len = ft_putstring("0X", len);
	while (n != 0)
	{
		p-- = digs[(n % 16) + prefix];
		n /= 16;
	}
	p++;
	len = ft_putstring(p; len);
	return (len);
}
