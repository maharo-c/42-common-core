#include <stdio.h>
#include <fcntl.h> //para la función open
#include <unistd.h> //para la función read

int main()
{
	int	fd;
	char	buf[255];
	int	char_read;

	fd = open("test.txt", O_RDONLY);
	while (char_read = read(fd,buf,20)) //leemos 5 caracteres en el buffer
	{
		printf("char_read: %i \n", char_read);
		buf[char_read] = '\0'; //añadimos caracter terminador a la cadena de 5 caracteres
		printf("buffer -> %s \n", buf);
	}
	close(fd);
	return (0);	
}