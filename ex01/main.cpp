#include "PhoneBook.hpp"

static int read_cmd(std::string &s);

int main(){
	PhoneBook pb;
	std::string s;
	while(1){
		read_cmd(s);
		pb.run_cmd(s);
		s.clear();
// #define DEBUG
#ifdef DEBUG
	pb.debug_show();
#endif
	}
	return 0;
}

static int read_cmd(std::string &s){
	puts_color("Please enter command ADD or SEARCH or EXIT)",  PINK_DIALOG);
	try{
// #define DEBUG2
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


void puts_color(std::string s, std::string color){
	std::cout << color << s << RESET_COLOR << std::endl;
}