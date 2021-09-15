#pragma once
#include <vector>
#include "Questions.h"
#include "UserStore.h"
#include <string>

class QuestionStore
{
private:
	static std::vector<Questions> question;
	Questions q;
public:
		
	QuestionStore();
	
	bool Ask_question(const UserStore& user, std::string question, int to_user_id);
	bool delete_question(const UserStore& user, int question_id);
	bool Answer_question(int question_id, std::string answer);
	
	const std::vector<Questions>& get_question_vector() const;


	const Questions& search_question_FromUserId(const UserStore& user) const;

	

	int get_question_size() const;
	~QuestionStore();
};

