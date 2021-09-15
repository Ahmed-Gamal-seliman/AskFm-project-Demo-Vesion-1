#include "controller_question.h"




void controller_question::print_questions_from_user(const UserStore& user) {
	
	for (auto& x : question_store.get_question_vector()) {
		
		if (x.get_from_user_id() == user.get_current_user().get_user_id())
			std::cout << "Question Id(" << x.get_question_id() << ") from " << user.get_current_user().get_user_name()
			<< "\tQuestion: " << x.get_parent_question() << std::endl;
	}

}



void controller_question::print_questions_to_user(const UserStore& user) {
	
	for (auto& x : question_store.get_question_vector()) {
		if (x.get_to_user_id() == user.get_current_user().get_user_id())
			std::cout <<"Question Id("<< x.get_question_id()<<") From User Id ("<<x.get_from_user_id()<<")\tQuestion: "
					  << x.get_parent_question() << std::endl;
	}
}



void controller_question::print_All_questions_and_Answers_for_user(const UserStore& user) {
	
	
	for (auto& x : question_store.get_question_vector()) {
		if (user.get_current_user().get_user_id() == x.get_from_user_id()) {
			std::cout << "Question Id(" << x.get_question_id() << ") from " << user.get_current_user().get_user_name()
				<< "\tQuestion: " << x.get_parent_question() << std::endl;


			for (auto& y : x.get_reply()) {

				std::cout << "Answer from " << user.search_user_name_for_id(x.get_to_user_id()) << ": ";
				std::cout << y << std::endl;
			}
		}
	}
}

