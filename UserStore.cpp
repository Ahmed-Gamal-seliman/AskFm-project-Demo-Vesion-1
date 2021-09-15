#include "UserStore.h"

UserStore::UserStore(): current_user(), user(), users(){
	//std::cout << "constructor UserStore" << std::endl;
}

const std::pair<User, bool>& UserStore::signin(std::string Email, std::string password) {
	
	std::pair<User, bool> p1;
	p1.second = 0;
	for (auto &x : users)
		if (x.get_Email() == Email && x.get_password() == password) {
			current_user = x;
			p1.second = 1;
		}
	p1.first = current_user;
	
	return p1;
}
void UserStore::signup(std::string Email, std::string password, std::string user_name, int user_id) {
	user.set_Email(Email);
	user.set_password(password);
	user.set_user_name(user_name);
	user.set_user_id(user_id);

	users.push_back(user);
}
void UserStore::signout() {
	exit(0);
}



const User& UserStore::get_current_user() const{
	return this->current_user;
}

const std::vector<User>& UserStore::get_users() const {
	return users;
}


const std::string& UserStore::search_user_name_for_id(int user_id) const {
	for (auto& x : users)
		if (x.get_user_id() == user_id)
			return x.get_user_name();

	return "";
}
UserStore::~UserStore() {
	//std::cout << "destructor UserStore" << std::endl;
}
