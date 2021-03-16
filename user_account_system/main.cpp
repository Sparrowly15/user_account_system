#include "account.h"
#include <vector>
#include <iostream>

void interact_with_account(int list_loc, vector<Account*>* accounts_list_ptr) {
	cout << "---------------------------------------------------------------" << endl;
	cout << "Login Succesful!" << endl;
	cout << "Current secret: " << (*accounts_list_ptr)[list_loc]->printSecret() << endl;
	cout << "---------------------------------------------------------------\n\n" << endl;
	return;
}

// finds index of account in accounts_list if it exists
int locate_account(string username_to_find, vector<Account*>* accounts_list_ptr) {
	int result = -1;									//location of user in the vector
	int vec_size = (*accounts_list_ptr).size();			//size of accounts_list vector

	for (int i = 0; i < vec_size; i++)
	{
		if ((*accounts_list_ptr)[i]->user_name == username_to_find)
		{
			result = i;
			break;
		}
	}
	return result;
}

// creates a new user account and pushes it to the list
int create_user(vector<Account*>* accounts_list_ptr) {
	string desired_username = "";	// for account creation
	string desired_password = "";	// for account creation

	//get username and password
	cout << "Please enter your desired username for the account." << endl;
	cout << "Username: ";
	cin >> desired_username;
	cout << endl;
	cout << "Please enter your desired password for the account." << endl;
	cout << "Password: ";
	cin >> desired_password;
	cout << endl;

	if (locate_account(desired_username, accounts_list_ptr) == -1)
	{
		Account* new_user = new Account(desired_username, desired_password);
		(*accounts_list_ptr).push_back(new_user);
		return 0;
	}
	else
	{
		return 1;
	}
}

// get username and password of account to log into, then allow user to interact with it if successful
void handle_login(vector<Account*>* accounts_list_ptr) {
	string given_username = "";		// for login
	string given_password = "";		// for login

	cout << "Please enter your username." << endl;
	cout << "Username: ";
	cin >> given_username;
	cout << endl;
	cout << "Please enter your password." << endl;
	cout << "Password: ";
	cin >> given_password;
	cout << endl;

	//confirm that account exists
	int username_check = locate_account(given_username, accounts_list_ptr);
	if (username_check == -1)
	{
		cout << "Error: incorrect username or password" << endl;
		return;
	}
	else
	{
		//account exists, check password
		bool is_pass_correct = false;
		is_pass_correct = (*accounts_list_ptr)[username_check]->comparePassword(given_password);
		if (is_pass_correct == false)
		{
			cout << "Error: incorrect username or password" << endl;
			return;
		}
		else if (is_pass_correct == true)
		{
			//function allows user to read and change stored secret
			interact_with_account(username_check, accounts_list_ptr);
		}
	}
	return;
}

int main()
{
	//create vector for all user accounts
	vector<Account*> accounts_list;

	while (true) {
		char choice = '0';
		string choice_buffer = "";

		cout << "Welcome to generic account manager!" << endl;
		cout << "Please enter the number of your selection:" << endl;
		cout << "\t1 : create new account\n"
				"\t2 : log in to existing account\n"
				"\t3 : exit\n" << endl;
		cout << "Selection: ";
		cin >> choice_buffer;
		cout << endl;

		//init user information
		choice = choice_buffer[0];
		switch (choice) {
		case '1' :
			if (create_user(&accounts_list) == 0) {	//return value 0 is success, nonzero is failure because account already exists
				cout << "Your account has been created!" << endl;
			}
			else {
				cout << "Error: account already exists!" << endl;
			}
			break;

		case '2':
			handle_login(&accounts_list); //get username and password of account to log into, then allow user to interact with it if successful
			break;

		case '3':
			cout << "Thank you for using generic account manager. Have a day." << endl;
			return 0;
			break;

		default :
			cout << "\nError: unrecognized command. Please enter a new command. Note: command should be a single character.\n" << endl;
		}
	}

	return 0;
}