#include "User.h"

int User::count_users = 0;
User::User()
			: user_name(""), password(""), Email(""), user_id(0) {
	
	++User::count_users;
	//std::cout << "constructor user" << std::endl;
}


void User::set_user_name(std::string user_name) {
	this->user_name = user_name;
}
void User::set_password(std::string password) {
	this->password = password;
}
void User::set_Email(std::string Email) {
	this->Email = Email;
}
void User::set_user_id(int user_id) {
	this->user_id = user_id;
}

const std::string& User::get_user_name() const{
	return this->user_name;
}
const std::string& User::get_password() const {
	return this->password;
}
const std::string& User::get_Email() const {
	return this->Email;
}
const int& User::get_user_id() const {
	return this->user_id;
}




User::~User() {
	//std::cout << "destructor user" << std::endl;
}




