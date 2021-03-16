#include "account.h"

Account::Account() {
	user_name = "";
	user_password = "";
	user_secret = "I have nothing to hide";
	return;
}

Account::Account(string new_user_name, string new_user_password) {			//constructor for class. Sets given use_name and user_password
	user_name = new_user_name;
	user_password = new_user_password;
	user_secret = "I have nothing to hide";
	return;
}

int Account::changePassword(string old_password, string new_password) {		//compares old_password to saved user_password, then changes user_password to new_password
	int status = 1; //default to failure
	if (comparePassword(old_password)) {
		user_password = new_password;
		status = 0; //success
	}
	return status;
}

bool Account::comparePassword(string given_password) {						//compares given_password to saved user_password
	bool status = false; //default to failure
	if (given_password.compare(user_password) == 0) {
		status = true;
	}
	return status;
}

void Account::changeSecret(string new_secret) {								//allows user to change their stored secret
	user_secret = new_secret;
}

string Account::printSecret() {												//prints user's stored secret
	return user_secret;
}