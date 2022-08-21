char	*get_next_line(int fd);
{
	int 	bytes;
	char	buff[BUFF_SIZE + 1];
	static char	*text[5000];
	char	*tmp;
	
	if (fd < 0 || BUFF_SIZE <= 0)
		return (0);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (text[fd] == NULL)
			text[fd] = ft_strdup[buff];
		else
		{
			tmp = ft_strjoin(text[fd], buff);
			free(text[fd]);
			text[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			return (its_okey(text, bytes, fd));
	}
	return (its_okey(text, bytes, fd));
}

char	its_okay(**text, int bytes, int fd)
{
	if (bytes <= 0 && text[fd] == NULL)
		return (0);
	else
		return (ft_line(text, bytes, fd));
}

char	ft_line(**text, int bytes, int fd)
{
	char	*line;
	int		len;
	char	*tmp;
	
	len = 0;
	while ((*text)[len] != '\0' && (*text)[len] != '\n')
		len++;
	if ((*text)[len] == '\n')
	{	line = ft_substr(*text, 0, len)
		tmp = ft_strdup(&((*text)[len + 1]));
		free(*text);
		*text = tmp;
		if ((*text)[0] == '\0')
		{
			free (*text);
			*text = 0;
		}
	else
	{
		*line = ft_strdup(*text);
		free (*text);
		*s = 0;
	}
	return (*line);
	}
}