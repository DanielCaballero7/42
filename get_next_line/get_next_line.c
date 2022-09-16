char	*get_next_line(int fd)
{
	int	i;
	int	buffer_len;
	char	*buffer;
	char	*left_str;
	char	*line;

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	while (read(fd, buffer, BUFFER_SIZE) > 0 && !ft_strchr(buffer, '\n'))
		line = ft_strjoin(line, buffer);
	left_str = ft_strchr(buffer, '\n');
	*left_str = '\0';
	line = ft_strjoin(line, buffer);
	buffer[BUFFER_SIZE] = '\0';
	i = ft_strlen(buffer) + 2;
	buffer[i - 1] = 'a';
	buffer_len = strlen(buffer) - i;
	left_str = ft_substr(buffer, i, buffer_len);
	free(buffer);
	return (line);
}
