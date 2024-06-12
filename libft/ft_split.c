#include "libft.h"

/**static int	count_words(char const *s, char c)
 * It counts the number of words in a string
 * 
 * @param char s The string to be split.
 * @param char c the delimiter
 * 
 * @return The number of words in the string.
 * 
 * 
 * 
 * static void	*ft_free(char **memry, size_t aux)
 * This function frees the memory allocated to the 2D array
 * 
 * @param char memry the memory to be freed
 * @param size_t aux is the number of lines in the file.
 * 
 * @return A pointer to a char.
 * 
 * 
 * 
 * * static void	split_str(char **ptr, char *str, char c, int nwords)
 * It splits a string into an array of strings, using a given character
 *  as a delimiter
 * 
 * @param char ptr the array of strings that will be returned
 * @param char str the string to be split
 * @param char c the character to split the string by
 * @param int nwords number of words in the string
 * 
 * @return A pointer to a pointer to a char.
 * 
 * 
 * 
 * 
 * char	**ft_split(char const *s, char c)
 * Split a string into an array of strings, using a given character 
 * as a delimiter
 * 
 * @param char s The string to be split.
 * @param char c the character to split the string by
 * 
 * @return A pointer to an array of pointers to characters.
 */
 

static int	count_words(char const *s, char c)
{
	int	cwords;
	int in_word;

	in_word = 0;
	cwords = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			cwords++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (cwords);
}

static void	*ft_free(char **memry, size_t aux)
{
	size_t	i;

	i = 0;
	while (i < aux)
	{
		free(memry[i]);
		i++;
	}
	free(memry);
	return (NULL);
}

static void	split_str(char **ptr, char *str, char c, int nwords)
{
	int		i;
	char	*start;

	i = 0;
	start = str;
	while (i < nwords)
	{
		while(*str && *str != c)
		{
			str++;
		}		
		ptr[i] = ft_substr(start, 0, str - start);
		if (!ptr[i])
		{
			ft_free(ptr, i);
			return ;
		}
		i++;
		while (*str == c)
			str++;
		start = str;
	}
	ptr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		nwords;
	char	**ptr;
	char	*str;
	char	delim[2];

	delim[0] = c;
	delim[1] = '\0';
	if (!s)
		return (NULL);
	str = ft_strtrim(s, delim);
	if (!str)
		return (NULL)
	nwords = count_words(str, c);
	ptr = ft_calloc((nwords + 1), sizeof(char *));
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	split_str(ptr, str, c, nwords);
	free(str);
	return (ptr);
}

