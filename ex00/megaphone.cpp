#include<iostream>

void str_toupper(char *s){
	for (int i=0; s[i]; ++i)
		if (islower(s[i]))
			s[i] = toupper(s[i]);
}

int main(int ac, char **av){
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for(int i = 1; i < ac; i++){
			str_toupper(av[i]);
			std::cout << av[i];
		}
	std::cout << std::endl;
	return 0;
}