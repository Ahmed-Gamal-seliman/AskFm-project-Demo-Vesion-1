#include "QuestionStore.h"


std::vector<Questions> QuestionStore::question = std::vector<Questions>();

QuestionStore::QuestionStore() {

}

bool QuestionStore::Ask_question(const UserStore& user, std::string question, int to_user_id) {
	++Questions::generate_question_id;

	q.set_question_id(Questions::generate_question_id);
	q.set_from_user_id(user.get_current_user().get_user_id());
	q.set_parent_question(question);

	for (auto& x : user.get_users()) {
		if (x.get_user_id() == to_user_id) {
			q.set_to_user_id(to_user_id);
			QuestionStore::question.push_back(q);
			return 1;
		}
	}

	return 0;
}


bool QuestionStore::delete_question(const UserStore& user, int question_id) {
	
	auto i = std::begin(QuestionStore::question);
	for (auto  &x : QuestionStore::question) {
		if (x.get_from_user_id() == user.get_current_user().get_user_id() && x.get_question_id() == question_id) {
			QuestionStore::question.erase(i);
			return 1;
		}
		else
			i++;
	}
	return 0;
}


bool QuestionStore::Answer_question(int question_id, std::string answer) {
	for (auto& x : QuestionStore::question) {
		if (x.get_question_id() == question_id) {
			x.set_reply_vector(answer);
			return 1;
		}
	}
	return 0;
}


const Questions& QuestionStore::search_question_FromUserId(const UserStore& user) const {
	Questions q;
	for (auto& x : question) {
		if (x.get_from_user_id() == user.get_current_user().get_user_id())
			return x;
	}
		return q;
}

const std::vector<Questions>& QuestionStore::get_question_vector() const{
	return this->question;
}

int QuestionStore::get_question_size() const{
	return (int)question.size();
}






QuestionStore::~QuestionStore() {

}