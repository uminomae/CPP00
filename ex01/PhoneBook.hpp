#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

const int MAX_C = 8;

class PhoneBook {
private:
	Contact book[MAX_C + 1];
	int num_data;
public:
	PhoneBook();
	void add_contact();
	void search_contact();
	void exit_book();
	void print_spec_row(int i);
	void print_all(int w, int idx);
	void debug_show();
};

#endif