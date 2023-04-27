#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	num_data = 0;
// #define DEBUG4
#ifdef DEBUG4
	std::cout << RED << "PhoneBook::PhonBook() constructor called" << RESET_COLOR << std::endl;
#endif
}


int PhoneBook::run_cmd(std::string &s){
	if (s == "ADD")
		add_contact();
	else if (s == "SEARCH")
		search_contact();
	else if (s == "EXIT")
		exit_book();
	else
		puts_color("Invalid command", RED);
	return 0;
}


void PhoneBook::add_contact(){
	if (num_data == MAX_C){
		int i = 0;
		for (i=0; i < MAX_C - 1; ++i)
			book[i] = book[i + 1];
		num_data = i;
	}
	puts_color("Please enter contact in the field", PINK_DIALOG);
	read_field(book[num_data].f_name, "first name", PINK_DIALOG_SUB);
	read_field(book[num_data].l_name, "last name", PINK_DIALOG_SUB);
	read_field(book[num_data].n_name, "nickname", PINK_DIALOG_SUB);
	read_field(book[num_data].p_number, "phone number", PINK_DIALOG_SUB);
	read_field(book[num_data].d_secret, "darkest secret", PINK_DIALOG_SUB);
	num_data++;
}

void PhoneBook::read_field(std::string &field, std::string s, std::string color){
	puts_color(s, color);
	try{
// #define DEBUG3
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



void PhoneBook::search_contact(){
	print_contact_list();
	bool is_put = false;
	while (!is_put)
		is_put = print_specified();
}


void PhoneBook::print_contact_list(){
	std::cout << "\n" << PINK_SHOW;
	std::cout << "Contacts list\n\n";
	std::cout << "|   index  |first name|last name | nickname |\n";
	for (int i = 0; i<num_data; ++i)
		print_summary(i);
	std::cout << "\n\n" << RESET_COLOR;
}

void PhoneBook::print_summary(int i){
	std::string id = std::to_string(i);
	std::cout << PINK_SHOW;
	std::cout << "|";
	print_summary_col(id);
	print_summary_col(book[i].f_name);
	print_summary_col(book[i].l_name);
	print_summary_col(book[i].n_name);
	std::cout << RESET_COLOR << std::endl;
}

void PhoneBook::print_summary_col(std::string &s){
	std::cout << std::right;
	if (s.size() > COL_W)
		std::cout << std::setw(COL_W - 1) << s.substr(0, 9) << "."  << "|";
	else
		std::cout << std::setw(COL_W) << s << "|";
}


bool PhoneBook::print_specified(){
	puts_color("Please enter the index", PINK_DIALOG);

	int idx;
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
		return false;
	}
	if (std::cin.eof()){
		puts_color("EOF accepted", RED);
		exit(1);
	}

	if (0 <= idx && idx < num_data){
		PhoneBook::print_contact(COL_W, idx);
		return true;
	}else
		puts_color("Invalid index value", RED);
	return 0;
}

void PhoneBook::print_contact(int w, int idx){
	std::string id = std::to_string(idx);
	std::cout << "\n" << PINK_SHOW_ALL;
	std::cout << "======================\n";
	print_line(w, "index", id);
	print_line(w, "first name", book[idx].f_name);
	print_line(w, "last name", book[idx].l_name);
	print_line(w, "nickname", book[idx].n_name);
	print_line(w, "p_number", book[idx].p_number);
	print_line(w, "d_secret", book[idx].d_secret);
	std::cout << "======================\n";
	std::cout << "\n\n" << RESET_COLOR;
}

void PhoneBook::print_line(int w, std::string key, std::string &s){
	std::cout << std::left;
	std::cout << std::setw(w) << key;
	std::cout << ":" << s << std::endl;
}



void PhoneBook::exit_book(){
	puts_color("Exit. All data will be erased", PINK_DIALOG);
	exit(0);
}


void PhoneBook::debug_show(){
	int i = 0;
	while (i < num_data){
		std::cout << "-------------------" << std::endl;
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
