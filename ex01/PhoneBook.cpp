#include <iostream>
#include <iomanip> 
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

const int COL_W = 10;

PhoneBook::PhoneBook(){
	num_data = 0;
}

void print_spec_col(std::string s){
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	if (s.size() > COL_W)
		std::cout << std::setw(COL_W - 1) << s.substr(0, 9) << "."  << "|";
	else
		std::cout << std::setw(COL_W) << s << "|";
}

void PhoneBook::print_spec_row(int i){
	std::cout << "\033[38;5;199m";
	print_spec_col(std::to_string(i));
	print_spec_col(book[i].f_name);
	print_spec_col(book[i].l_name);
	print_spec_col(book[i].n_name);
	std::cout << std::endl;
	std::cout << "\033[m";
}

void print_line(int w, std::string key, std::string s){
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << std::setw(w) << key;
	std::cout << ":" << s << std::endl;
}

void PhoneBook::print_all(int w, int idx){
	std::cout << "\033[38;5;201m";
	print_line(w, "index", std::to_string(idx));
	print_line(w, "first name", book[idx].f_name);
	print_line(w, "last name", book[idx].l_name);
	print_line(w, "nickname", book[idx].n_name);
	print_line(w, "p_number", book[idx].p_number);
	print_line(w, "d_secret", book[idx].d_secret);
	std::cout << "\033[m";
}

void print_invalid(){
	std::cout << "\033[31m";
	std::cout << "It's wrong. Please enter a valid number";
	std::cout << "\033[m" << std::endl;
}

void PhoneBook::search_contact(){
	int i, idx;
	for (i = 0; i<num_data; ++i)
		print_spec_row(i);
	std::cin >> idx;
	if (0 <= idx && idx <= num_data)
		print_all(COL_W, idx);
	else
		print_invalid();
}

void PhoneBook::add_contact(){
	int i = 0;
	if (num_data == MAX_C){
		while(i < MAX_C - 1){
			book[i] = book[i + 1];
			i++;
		}
		num_data = i;
	}
	std::cin >> book[num_data].f_name;
	std::cin >> book[num_data].l_name;
	std::cin >> book[num_data].n_name;
	std::cin >> book[num_data].p_number;
	std::cin >> book[num_data].d_secret;
	num_data++;
}

int main(){
	PhoneBook pb;
	std::string s;

	while(s != "EXIT"){
		std::cout << "CMD: ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, s);
		if (s == "ADD")
			pb.add_contact();
		else if (s == "SEARCH")
			pb.search_contact();
	}

// #define DEBUG
#ifdef DEBUG
	pb.debug_show();
#endif

	return 0;
}