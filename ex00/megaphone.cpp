#include <iostream>
#include <string>

int main(int ac, char **av){
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		for(int i = 1; i < ac; i++){
			std::string s = av[i];
			for (int i=0; s[i]; ++i)
				s[i] = toupper(s[i]);
			std::cout << s;
		}
	}
	std::cout << std::endl;
	return 0;
}