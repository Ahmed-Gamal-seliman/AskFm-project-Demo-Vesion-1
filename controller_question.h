#pragma once
#include "QuestionStore.h"
#include "UserStore.h"

class controller_question
{
private:
	QuestionStore question_store;
public:
	void print_questions_from_user(const UserStore& user);
	void print_questions_to_user(const UserStore& user);
	void print_All_questions_and_Answers_for_user(const UserStore& user);
};

