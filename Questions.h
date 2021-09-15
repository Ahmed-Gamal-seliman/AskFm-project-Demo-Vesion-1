#pragma once
#include "User.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <vector>



class Questions
{
	
private:
	std::string parent_question;
	int question_id;
	int from_user_id;
	int to_user_id;
	 std::vector<std::string> reply;
public:
	static int generate_question_id;
	Questions();

		
		void set_parent_question(std::string parent_question);
		void set_from_user_id(int from_user_id);
		void set_to_user_id(int to_user_id);
		void set_reply_vector(std::string reply);
		void set_question_id(int generate_question_id);

		int get_from_user_id() const;
		int get_to_user_id() const;
		int get_question_id() const;
		const std::vector<std::string>& get_reply() const;
		const std::string& get_parent_question() const;



	

	~Questions();
};

