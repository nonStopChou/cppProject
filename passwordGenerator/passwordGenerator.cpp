#include <stdio.h>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

#define yesNoText(condition) (condition ? "\x1b[32m Yes" : "\x1b[31m No")

using namespace std;

bool INCLUDE_SPECIAL_CHARACTER = false;
bool INCLUDE_NUMBER = false;
bool INCLUDE_ALPHABET = false;
int PASSWORD_LENGTH = 10;
const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string special = "!@#$%^&*():;~-*+={}[]";
const string number = "0123456789";

#if defined(__APPLE__)
	const char* cleanScreen = "clear";
#elif defined(__WIN32__)
	const char* cleanScreen = "CLS";
#elif defined(__WIN64__)
	const char* cleanScreen = "CLS";
#endif

string operator*(const string &s, size_t n){
	string result;
	result.resize(s.size() * n);
	for(size_t i = 0 ; i < n; ++i){
		result += s;
	}
	return result;
}

string setStringColor(const string &s, const string &color){
	if(color == "red") return "\x1b[31m" + s;
	if(color == "green") return "\x1b[32m" + s;
	if(color == "black") return "\x1b[30m" + s;
	if(color == "white") return "\x1b[37m" + s;
	if(color == "yello") return "\x1b[33m" + s;
	return s;
}

string generatePassWord(){
	string result;
	string characterSet;
	if(INCLUDE_SPECIAL_CHARACTER) characterSet += special;
	if(INCLUDE_ALPHABET) characterSet += alphabet;
	if(INCLUDE_NUMBER) characterSet += number;
	size_t string_length = characterSet.length();
	if(!string_length) return setStringColor("Need to set password format !", "red");
	for(size_t i = 0; i < PASSWORD_LENGTH; i++){
		result += characterSet[rand() % string_length];
	}
	return result;
}

int main(int argc, char *argv[]){

	if(argc == 2 && strcmp(argv[1], "--help") == 0){
		cout << "-alpha : set the password include alphabet [a-zA-Z]" << endl;
		cout << "-number : set the password include number [0-9]" << endl;  
		return 0;
	}

	srand(time(NULL));
		
	string input;

	for(int i = 0; argv[i] != NULL; i++){
		if(strcmp(argv[i], "-alpha") == 0) INCLUDE_ALPHABET = true;
		if(strcmp(argv[i], "-number") == 0) INCLUDE_NUMBER = true;
	}

	while(true){
		
		system(cleanScreen);
		
		cout << setStringColor("!!! Welcome to password generator !!!", "white") << endl;
		cout << setStringColor("Enter the number to change the mode ! [1-4]\n", "white") << endl;
	 	cout << setStringColor(string("-") * 25, "white") << endl;	
		cout << setStringColor("\nCurrent setting as following", "yello") << endl;	
		cout << setStringColor("0. Exit", "white") << endl;
		cout << setStringColor("1. Password contain special character ? ", "white") << yesNoText(INCLUDE_SPECIAL_CHARACTER) << endl;
		cout << setStringColor("2. Password contain number ?", "white") << yesNoText(INCLUDE_NUMBER) << endl;
		cout << setStringColor("3. Password contain alphabet ? ", "white") << yesNoText(INCLUDE_ALPHABET) << endl;
		cout << setStringColor("4. Password Length = ", "white") << setStringColor(to_string(PASSWORD_LENGTH), "green") << endl;
		cout << setStringColor("5. Generate password !", "white") << endl;
		cout << setStringColor(string("-") * 25, "white") << endl;	
		if(input == "5"){
			string newPassword = setStringColor(generatePassWord(), "yello");
			cout << setStringColor("The generated password is : ", "white") + newPassword << endl;
		}
		cout << setStringColor("Input : ", "white") << endl;
		cin >> input;
		if(input == "0") break;
		if(input == "1") INCLUDE_SPECIAL_CHARACTER = !INCLUDE_SPECIAL_CHARACTER;
		if(input == "2") INCLUDE_NUMBER = !INCLUDE_NUMBER;
		if(input == "3") INCLUDE_ALPHABET = !INCLUDE_ALPHABET;
		if(input == "4"){
			cout << setStringColor("Input the length of password : ", "white") << endl;
			try{
				scanf("%d", &PASSWORD_LENGTH);
			}catch(exception e){
				setStringColor("The input need to be valid number !", "red");
			}
		}

	}

	return 0;

}