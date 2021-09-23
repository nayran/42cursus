#ifndef CLASSDATA_HPP
# define CLASSDATA_HPP 

#include <iostream>
#include <string.h>

class Data {
private:
	std::string		firstName;
	std::string		lastName;
	std::string		nickname;
	std::string		phoneNumber;
	std::string		drkstSecret;
	int				num;

public:
	static void		addContact(Data *c);
	static void		searchContacts(Data *c);

	Data(void);
	~Data(void);
};

//				PHONEBOOK.cpp
std::string		ft_getnum();
std::string		ft_getinfo();
std::string		ft_menu();

//				UTILS.cpp
std::string		ft_endstr(std::string s, int pos);
int				ft_strlen(std::string s);
void			ft_formatprint(std::string s);
int				ft_isallnum(std::string info);

#endif
