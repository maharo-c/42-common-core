/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:47 by margarita         #+#    #+#             */
/*   Updated: 2024/06/28 18:19:06 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*read_text(int fd, char *text)
{
	/*Función que devuelve un string
	/* que contiene o un salto de línea
	/* o que ha llegado al final del
	/* archivo*/

	char	*buffer; //string que va a almacenar los caracteres leídos por un buffer de tamaño "buffer_size"
	int		rdbytes; //flag para controlar lo que se está leyendo
	
	//si el puntero text es NULL, reservamos un byte de memoria para almacenar al menos 1 char
	if (!text)
		text = ft_calloc(1, 1);
	//reservamos memoria para el buffer (damos un byte más para el terminador de string)
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//si ha habido fallo en la reserva de memoria, devolvemos NULL
	if (!buffer)		
		return (NULL);
	//si la reserva se ha hecho correctamente, inicializamos la flag a 1 y procedemos a leer buffer_size bytes del fichero de textp
	rdbytes = 1;
	while (rdbytes > 0)
	{
		rdbytes = read(fd, buffer, BUFFER_SIZE);//si no llega al final del fichero, rdbytes será igual a BUFFER_SIZE
		if (rdbytes == -1) //comprueba que no haya habido error con la función "read"
		{	//si hay fallo, libera las dos strings y devuelve NULL
			free(text);
			free(buffer);
			return(NULL);
		}
		//si la lectura de bytes ha sido correcta, completamos el string buffer con el caracter terminado de cadena de caracteres
		buffer[rdbytes] = '\0';
		//la función ft_join_and_free une las cadenas buffer y text
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			//si se detecta el carácter salto de línea en text, salimos del while
			break;
	}
	free (buffer); //liberamos el buffer
	return (text); //devolvemos un texto que al menos contiene un salto de línea o que ha llegado al final del fichero
}

char	*get_line(char *text)
{
	/**
	 * Esta función devuelve una línea de texto completa (hasta alcanzar un salto de línea)
	 */
	int		i; //vble para iterar en el string "text"
	char	*str; //la string a ser devuelta

	i = 0;
	//si el string está vacío, devolvemos NULL
	if (!text[i])
		return (NULL);
	//recorremos "text" buscando el carácter '\n'
	while (text[i] && text[i] != '\n')
		i++;
	//cuando sale del bucle, la variable i nos indica el número de caracteres de la línea -1 y sin '\n'
	str = ft_calloc(i + 2, sizeof(char)); //reservamos memoria para nuestra next_line. El tamaño reservado es "i+2" porque i empezaba en 0 y tengo que añadir un hueco más para el '\n'
	//copiamos en la cadena str la línea de texto
	str = ft_strncpy(text, str, i+2);
	return (str);
}

char	*clean_text(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text; //readen string from the file with the buffer size
	char		*next_line; //the wanted line
		
	//checking fd and buffer size are ok
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//if both are ok, then function read is called for getting a string with a buffer_size
	text = read_text(fd, text) ;
	//if any problem occurs, the function read_text returns NULL
	if (!text)
		return(NULL);
	//if the string "text" not is NULL, the function get_line delivers the wanted next_line from the readen text
	next_line = get_line(text);
	//clean_text delete the string "next_line" from the string "text"
	text = clean_text(text);
	return (next_line);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	fd = close(fd);
	return 0;
} 