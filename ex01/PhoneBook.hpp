#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

const int MAX_C = 8;
const int COL_W = 10;
const std::string PINK1 = "\033[38;5;201m";
const std::string PINK2 = "\033[38;5;199m";
const std::string RED = "\033[31m";
const std::string RESET_COLOR = "\033[m";

class PhoneBook {
private:
	Contact book[MAX_C];
	int num_data;
public:
	PhoneBook();
	void add_contact();
	void search_contact();
	void exit_book();
	int run_cmd(std::string &s);
	void read_field(std::string &field, std::string s, std::string color);
	void print_summary(int i);
	void print_contact(int w, int idx);
	void debug_show();
};

#endif