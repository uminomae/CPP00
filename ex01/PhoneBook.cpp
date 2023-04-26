#include <iostream>
#include <iomanip> 
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	num_data = 0;
}

void puts_color(std::string s, std::string color){
	std::cout << color << s << RESET_COLOR << std::endl;
}

void print_summary_col(std::string &s){
	std::cout << std::right;
	if (s.size() > COL_W)
		std::cout << std::setw(COL_W - 1) << s.substr(0, 9) << "."  << "|";
	else
		std::cout << std::setw(COL_W) << s << "|";
}

void PhoneBook::print_summary(int i){
	std::string id = std::to_string(i);
	std::cout << PINK1;
	print_summary_col(id);
	print_summary_col(book[i].f_name);
	print_summary_col(book[i].l_name);
	print_summary_col(book[i].n_name);
	std::cout << RESET_COLOR << std::endl;
}

void print_line(int w, std::string key, std::string &s){
	std::cout << std::left;
	std::cout << std::setw(w) << key;
	std::cout << ":" << s << std::endl;
}

void PhoneBook::print_contact(int w, int idx){
	std::string id = std::to_string(idx);
	std::cout << PINK1;
	print_line(w, "index", id);
	print_line(w, "first name", book[idx].f_name);
	print_line(w, "last name", book[idx].l_name);
	print_line(w, "nickname", book[idx].n_name);
	print_line(w, "p_number", book[idx].p_number);
	print_line(w, "d_secret", book[idx].d_secret);
	std::cout << RESET_COLOR;
}

void PhoneBook::search_contact(){
	int i, idx;
	for (i = 0; i<num_data; ++i)
		print_summary(i);
	
	bool is_put = false;
	while (!is_put){
		puts_color("Please enter the index", PINK2);
		try{
			std::cin >> idx;
		}catch(...){
			puts_color("Exception accepted", RED);
			exit(1);
		}
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			puts_color("Error in cin", RED);
			continue;
		}
		if (std::cin.eof()){
			puts_color("EOF accepted", RED);
			exit(1);
		}

		if (0 <= idx && idx < num_data){
			is_put = true;
			print_contact(COL_W, idx);
		}
		else{
			puts_color("Invalid index value", RED);
		}
	}
}

// #define DEBUG3

void PhoneBook::read_field(std::string &field, std::string s, std::string color){
	puts_color(s, color);
	try{
#ifdef DEBUG3
	throw("error");
#endif
		std::cin >> field;
	}catch(...){
		puts_color("Exception accepted", RED);
		exit(1);
	}
	if (std::cin.eof()){
		puts_color("EOF accepted", RED);
		exit(1);
	}
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
	puts_color("Enter contact in the field", PINK2);
	read_field(book[num_data].f_name, "first name", PINK1);
	read_field(book[num_data].l_name, "last name", PINK1);
	read_field(book[num_data].n_name, "nickname", PINK1);
	read_field(book[num_data].p_number, "phone number", PINK1);
	read_field(book[num_data].d_secret, "darkest secret", PINK1);
	num_data++;
}

int PhoneBook::run_cmd(std::string &s){
	if (s == "ADD")
		add_contact();
	else if (s == "SEARCH")
		search_contact();
	else if (s == "EXIT")
		exit(0);
	else
		puts_color("Invalid command", RED);
	return 0;
}

// #define DEBUG2

int read_cmd(std::string &s){
	puts_color("Please enter command ADD or SEARCH or EXIT)",  PINK2);
	try{
#ifdef DEBUG2
	throw("error");
#endif
		std::cin >> s;
	}catch(...){
		puts_color("exception accepted", RED);
		exit(1);
	}
	if (std::cin.eof()){
		puts_color("EOF accepted", RED);
		exit(1);
	}
	return 0;
}

// #define DEBUG

int main(){
	PhoneBook pb;
	std::string s;
	while(1){
		read_cmd(s);
		pb.run_cmd(s);
		s.clear();
#ifdef DEBUG
	pb.debug_show();
#endif
	}
	return 0;
}
