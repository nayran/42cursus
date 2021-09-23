#include "ClassData.hpp"

std::string	ft_endstr(std::string s, int pos)
{
	int x;

	x = pos - 1;
	while (s[++x])
		s[x] = '\0';
	return (s);
}

int			ft_strlen(std::string s)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void		ft_formatprint(std::string s)
{
	if (ft_strlen(s) > 10)
	{
		s[9] = '.';
		s = ft_endstr(s, 10);
	}
	std::cout.setf ( std::ios::right | std::ios::showbase );
	std::cout.width(10);
	std::cout << s << '|';
}

int			ft_isallnum(std::string info)
{
	int x;

	x = -1;
	if (info[0] == '\0')
		return (0);
	while (info[++x])
	{
		if (info[x] < '0' || info[x] > '9')
			return (0);
	}
	return (1);
}
