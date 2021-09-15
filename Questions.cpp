#include "Questions.h"

int Questions::generate_question_id = 99;

Questions::Questions(): parent_question(""),question_id(0),  from_user_id(0), to_user_id(0),reply() {
	

	//std::cout << "constructor Questions" << std::endl;
}



void Questions::set_parent_question(std::string parent_question) {
	this->parent_question = parent_question;
}


void Questions::set_reply_vector(std::string reply) {
	this->reply.push_back(reply);
}
const std::vector<std::string>& Questions::get_reply() const {
	return reply;
}



void Questions::set_from_user_id(int from_user_id) {
	this->from_user_id = from_user_id;
}
void Questions::set_to_user_id(int to_user_id) {
	this->to_user_id = to_user_id;
}

void Questions::set_question_id(int generate_question_id) {
	question_id = generate_question_id;
}


int Questions::get_from_user_id() const {
	return this->from_user_id;
}
int Questions::get_to_user_id() const {
	return this->to_user_id;
}


int Questions::get_question_id() const {
	return question_id;
}

const std::string& Questions::get_parent_question() const {
	return parent_question;
}

Questions::~Questions() {
	//std::cout << "destructor Questions" << std::endl;
}
