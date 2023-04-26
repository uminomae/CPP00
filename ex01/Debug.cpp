#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::debug_show(){
	int i = 0;
	while (i < num_data){
		std::cout << i << std::endl;
		std::cout << book[i].f_name << std::endl;
		std::cout << book[i].l_name << std::endl;
		std::cout << book[i].n_name << std::endl;
		std::cout << book[i].p_number << std::endl;
		std::cout << book[i].d_secret << std::endl;
		std::cout << "-------------------" << std::endl;
		i++;
	}
}
