size_t	ft_strlen(const char *s)
{	
	unsigned int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*str_aux;

	str_aux = (char *)s;
	while (*str_aux != c)
		if (*str_aux == '\0')
			return (NULL);
		else
			str_aux++;
	return (str_aux);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	
	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!new_str)
		return (NULL);
	while (*s1 != '\0')
		*new_str++ = *s1++;
	while (*s2 != '\0')
		*new_str++ = *s1++;
	*new_str = '\0';
       return (new_str);	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_aux;
	char	*newstr;
	int	i;

	newstr = malloc((len + 1) * sizeof (char*));
	if (!newstr)
		return (NULL);
	str_aux = (char *)s;
	i = 0;
	while (i != start)
		i++;
	while (len-- > 0)
		*newstr++ = str_aux[i++];
	return (newstr);
}
