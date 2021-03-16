#pragma once
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Account
{
	public:
		string user_name;
		string registration_date;

		//function declarations
		Account();
		Account(string new_user_name, string new_user_password);
		int changePassword(string old_password, string new_password);	//fails if initial value is empty string or old_password doesn't match the user_password variable
		bool comparePassword(string given_password);					//returns true if given_password matches user_password and false otherwise
		void changeSecret(string new_secret);
		string printSecret();

	private:
		string user_password;
		string user_secret;
};

