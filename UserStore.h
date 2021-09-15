#pragma once
#include <vector>
#include "User.h"
#include <iostream>
#include <utility>

class UserStore
{
private:
	std::vector<User> users;
	User user;
	User current_user;

public:
	UserStore();

	const std::pair<User, bool>& signin(std::string Email, std::string password);
	void signup(std::string Email, std::string password, std::string user_name, int user_id);
	void signout();

	const User& get_current_user() const;
	const std::vector<User>& get_users() const;

	const std::string& search_user_name_for_id(int user_id) const;

	
	~UserStore();
};

