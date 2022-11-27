#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
    int len;

    len = 0;
	while(str[len])
	{
		len++;
	}
	char *new_str = malloc(sizeof(char) * (len + 1));
	if(!new_str)
	{
		return (0);
	}
	int i = -1;
	while(++i < len)
	{
		new_str[i] = str[i];
	}
	new_str[i] = 0;
    char *s2 = new_str;
    free(new_str);
	return (s2);
}

char *get_next_line(int fd)
{
    char heap[7000000] = {0};
    char buff;
    int nbyte = 0;
    int i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((nbyte = read(fd, &buff, 1)) && nbyte >= 0)
    {
        heap[i] = buff;
        if (buff == '\n')
            break;
        i++;    
    }
    heap[i] = '\n';
    return ft_strdup(heap);
}

int main()
{
    int i = 0;
    int j = 0;
    int fd = open("test", O_RDONLY);
    //get_next_line(fd);
    //close(fd);
    // printf("%d = %s", j, get_next_line(fd));
    while(i < 117)
    {
        printf("%d = %s", j, get_next_line(fd));
        i++;
        j++;
    }
}
