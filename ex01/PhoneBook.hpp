#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip> 
#include "Contact.hpp"

const int MAX_C = 8;
const int COL_W = 10;

const std::string PINK_SHOW = "\033[38;5;183m";
const std::string PINK_SHOW_ALL = "\033[38;5;201m";
const std::string PINK_DIALOG_SUB = "\033[38;5;170m";
const std::string PINK_DIALOG = "\033[38;5;198m";
const std::string RED = "\033[38;5;52m";
const std::string RESET_COLOR = "\033[m";

class PhoneBook {
private:
	Contact book[MAX_C];
	int num_data;

	void add_contact();
	void search_contact();
	void read_field(std::string &field, std::string s, std::string color);
	void print_summary(int i);
	bool print_specified();
	void print_contact(int w, int idx);
	void print_line(int w, std::string key, std::string &s);
	void print_summary_col(std::string &s);
	void exit_book();
	void print_contact_list();
public:
	PhoneBook();
	int run_cmd(std::string &s);
	void debug_show();
};

void puts_color(std::string s, std::string color);

#endif