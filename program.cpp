#include "program.h"

program::program()  {

}

void program::Menu_of_login_and_signup() {
	std::cout << "Menu:" << "\n" << "\t1: Login" << "\n\t2: signup"<<"\n\t3: exit" << std::endl;
}

bool program::run_of_signin() {
	
	std::string email, password;

	std::cin.ignore();

	std::cout << "Enter Email: ";
	std::getline(std::cin, email);

	std::cout << "Enter password: ";
	std::getline(std::cin, password);

	if (userstore.signin(email, password).second == 0) {
		std::cout << "Login faild" << std::endl;
		return 0;
	}
		std::cout << "Login sucessfully...\n" << "Welcome " << userstore.get_current_user().get_user_name() << std::endl;
		return 1;
	
	
}


void program::run_of_signup() {
	std::string email, password, username;
	int userid;
	
	std::cin.ignore();
	std::cout << "Enter Email: "; 
	std::getline(std::cin, email);
	

	std::cout << "Enter Password: ";
	std::getline(std::cin, password);
	

	std::cout << "Enter User Name: ";
	std::getline(std::cin, username);


	std::cout << "Enter id: ";
	std::cin >> userid;

userstore.signup(email, password, username, userid);
}



void program::menu_of_choices_after_login() {
	std::cout << "Menu:" << "\n"
			  << "\t1: Print Questions To Me" 
			  << "\n\t2: Print Questions From Me" 
			  << "\n\t3: Answer Question"
		      << "\n\t4: Delete Question"
		      << "\n\t5: Ask Question"
		      << "\n\t6: print All Questions and Answers"
			  << "\n\t7: Lsit of users"
			  << "\n\t8: Logout"
			  << std::endl;
}

void program::run_print_questions_to_user(const UserStore& user) {
	ControllerQuestion.print_questions_to_user(user);
}

void program::run_print_questions_from_user(const UserStore& user) {
	ControllerQuestion.print_questions_from_user(user);
}

void program::run_Answer_question(int question_id, std::string answer) {
	if (question_store.Answer_question(question_id, answer))
		std::cout << "\t** Answer is sent **" << std::endl;
	else
		std::cout << "\t Answer doesn't sent please check the Question Id" << std::endl;
}

void program::run_Delete_question(const UserStore& user, int question_id) {
	if (question_store.delete_question(user, question_id))
		std::cout << "\t** Question Deleted sucessfully.. **" << std::endl;
	else
		std::cout << "\tQuestion isn't deleted please check question id." << std::endl;
	
}

void program::print_All_users() {
	for (auto& x : userstore.get_users())
		std::cout <<"ID (" <<x.get_user_id()<<")\t" << x.get_user_name() << std::endl;
}

void program::run_Ask_question(const UserStore& user, std::string question, int to_user_id) {
	if (question_store.Ask_question(user, question, to_user_id)) {
		std::cout << "\t** Question is sent.... **" << std::endl;
	}
	else
		std::cout << "\tQuestion doesn't sent please check the User Id" << std::endl;
}

void program::print_All_questions_and_Answers_for_user(const UserStore& user) {
	ControllerQuestion.print_All_questions_and_Answers_for_user(user);
}

void program::run_signout() {
	userstore.signout();
}


void program::Run() {
	int choice{ 0 };
	while (1) {
		Menu_of_login_and_signup();

		std::cout << "Enter number in range 1 - 3: ";
		std::cin >> choice;

		bool flag = 0;

		switch (choice) {
		case 1: flag= run_of_signin(); break;

		case 2: run_of_signup(); break;
		case 3: run_signout(); break;

		default:std::cout << "ERROR: invalid number!!!" << std::endl;
		}

		if (choice == 1) {
			
			while (flag) {
				menu_of_choices_after_login();

				std::cout << "Enter numeber in range 1 - 8: ";
				std::cin >> choice;
				switch (choice) {
				case 1:	run_print_questions_to_user(userstore); break;
				case 2:	run_print_questions_from_user(userstore);	break;

				case 3:
				{
					int question_id;
					std::string answer;

					std::cout << "Enter Question Id you want to Answer: ";
					std::cin >> question_id;

					std::cin.ignore();

					std::cout << "Enter your answer: ";
					std::getline(std::cin, answer);

					run_Answer_question(question_id, answer);	
				}
				break;

				case 4:
				{
					int question_id{ 0 };
					std::cout << "Enter the Question Id you want to delete: ";
					std::cin >> question_id;
					run_Delete_question(userstore, question_id); 
				}
				break;

				case 5:
				{
					std::string question;
					int to_user_id;

					std::cin.ignore();

					std::cout << "Enter the question: ";
					std::getline(std::cin, question);

					std::cout << "Enter the User Id you want to send this Question: ";
					std::cin >> to_user_id;

					run_Ask_question(userstore, question, to_user_id);	
				}
				break;

				case 6:	print_All_questions_and_Answers_for_user(userstore);	break;
				case 7: print_All_users(); break;

				case 8:	flag=0; break;
				default: std::cout << "ERROR invalid number!!!" << std::endl;
				}

			}
		}
	}

}


program::~program() {

}