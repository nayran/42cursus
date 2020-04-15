#include "cub3D.h"

int main(int argc, char **argv)
{
	t_godfather all;
	int i;
	char	*c;
	int x;
	int y;

	c = argv[1];
	i = 0;
    x = 0;
	all = ft_lecube(c);
    while (x < 2)
        printf("%i\n", all.caso.r[x++]);
    return (0);
}
