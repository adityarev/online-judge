#include <cstdio>
#include <functional>
#include <iostream>
#include <map>

const std::string REGISTER = "register";
const std::string LOGIN = "login";
const std::string LOGOUT = "logout";

struct User {
	std::string password;
	bool logged_in;
	
	User() {}
	
	User(std::string &password) {
		this->password = password;
		this->logged_in = false;
	}
};

void
run_action(std::map<std::string,struct User> &db) {
	std::string action;
	std::cin >> action;
	
	std::function<void(std::string&, std::string&)> regis = [&](
		std::string &name,
		std::string &password
	) -> void {
		if (db.find(name) == db.end()) {
			struct User user = User(password);
			db[name] = user;
			
			std::cout << "success: new user added" << std::endl;
			
		} else {
			std::cout << "fail: user already exists" << std::endl;
		}
	};
	
	std::function<void(std::string&, std::string&)> login = [&](
		std::string &name,
		std::string &password
	) -> void {
		if (db.find(name) == db.end()) {
			std::cout << "fail: no such user" << std::endl;
		} else {
			struct User *user = &db[name];
			if (user->password == password) {
				if (user->logged_in) {
					std::cout << "fail: already logged in" << std::endl;
				} else {
					user->logged_in = true;
					std::cout << "success: user logged in" << std::endl;
				}
			} else {
				std::cout << "fail: incorrect password" << std::endl;
			}
		}
	};
	
	std::function<void(std::string&)> logout = [&](
		std::string &name
	) -> void {
		if (db.find(name) == db.end()) {
			std::cout << "fail: no such user" << std::endl;
		} else {
			struct User *user = &db[name];
			if (user->logged_in) {
				user->logged_in = false;
				std::cout << "success: user logged out" << std::endl;
			} else {
				std::cout << "fail: already logged out" << std::endl;
			}
		}
	};
	
	std::string name;
	std::string password;
	
	if (action == REGISTER) {
		std::cin >> name;
		std::cin >> password;
		regis(name, password);
	}
	if (action == LOGIN) {
		std::cin >> name;
		std::cin >> password;
		login(name, password);
	}
	if (action == LOGOUT) {
		std::cin >> name;
		logout(name);
	}
}

int
main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);
	
	std::map<std::string,struct User> db;
	db.clear();
	
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
		run_action(db);
	
	return 0;
}

