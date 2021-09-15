#pragma once
#include <iostream>
#include <string>
#include "UserStore.h"
#include "controller_question.h"
#include "QuestionStore.h"
class program
{
private:
	UserStore userstore;
	controller_question ControllerQuestion;
	QuestionStore question_store;
	
public:
	program();

	bool run_of_signin ();
	void run_of_signup();

	

	void Run();

	void menu_of_choices_after_login();
	void Menu_of_login_and_signup();


	void run_print_questions_to_user(const UserStore& user);
	void run_print_questions_from_user(const UserStore& user);
	void run_Answer_question(int question_id, std::string answer);
	void run_Delete_question(const UserStore& user, int question_id);
	void run_Ask_question(const UserStore& user, std::string question, int to_user_id);
	void print_All_questions_and_Answers_for_user(const UserStore& user);
	void print_All_users();
	void run_signout();


	~program();
};

