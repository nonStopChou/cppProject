#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

using namespace std;

string operator*(const string &s, size_t n){
	string result;
	for(size_t i = 0; i < n; ++i){
		result += s;
	}	
	return result;
}

void printGameStatus(int game[3][3]){
	
	string gameStatus;
	for(int i = 0; i < 3; i++){

		string line = "";
		line += string("-") * 20 + "\n";
		line += "|  ";
		for(int j = 0 ; j < 3 ; j++){
			if(game[i][j] != -1){
				line += (game[i][j] == 1) ? "O" : "X";
			}else{
				line += " ";
			}
			line += "  |  ";
		}
		gameStatus += line + "\n";
	}
	gameStatus += string("-") * 20;
	cout << gameStatus << endl;
}

void takeAction(int game[3][3], bool status){
	int pos = 0;
	while(true){
		cin >> pos; 
		if(game[pos/3][pos%3] == -1){
			if(status){
				game[pos/3][pos%3] = 1;
				return;
			}else{
				game[pos/3][pos%3] = 0;
				return;
			}	
		}else{
			cout << "The position already filled" << endl;
		}	
	}
}

int checkStatus(int game[3][3]){
	int winningState[8] = {7, 56, 73, 87, 146, 273, 292, 448};
	int player1 = 0, player2 = 0;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3; j++){
			if(game[i][j] == 1){
				player1 += 1<<(i*3+j);
			}else if(game[i][j] == 0){
				player2 += 1<<(i*3+j);
			}
		}
	}
	for(int i = 0 ; i < 8 ; i++){
		if((player1 & winningState[i]) == winningState[i]) return 1;
		if((player2 & winningState[i]) == winningState[i]) return -1;
	}
	return 0;
}

int main(int argc, char* argv[]){

	int game[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	bool pending = true;
	bool status = false;
	int step = 0;
	while(pending){
		system("clear");
		printGameStatus(game);
		takeAction(game, status);
		if(checkStatus(game) == 1){
			pending = false;
			cout << "Player1 win !" << endl;
			return 0;
		}	

		if(checkStatus(game) == -1){
			pending = false;
			cout << "Player2 win !" << endl;
			return 0;
		}	

		status = !status;
		step += 1;
		if(step == 9){
			cout << "Draw" << endl;
			return 0;
		}
	}
	
	
}
