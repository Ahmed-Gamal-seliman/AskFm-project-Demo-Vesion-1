#pragma once
#include <string>
#include <iostream>
class User
{

private:
	std::string user_name;
	std::string password;
	std::string Email;
	int user_id;
	static int count_users;

public:
	User();
	void set_user_name(std::string user_name);
	void set_password(std::string password);
	void set_Email(std::string Email);
	void set_user_id(int user_id);

	const std::string& get_user_name() const;
	const std::string& get_password() const;
	const std::string& get_Email() const;
	const int& get_user_id() const;


	
	~User();
	

};

