#include<iostream>
#include "UTTT.h"
#include<fstream>
using namespace std;

TicTacToe::TicTacToe() {
	board = 3;
	tp = new char** [9];
	for (int i = 0; i < 9;i++) {
		tp[i] = new char* [3];
		for (int j = 0; j < 3;j++) {
			tp[i][j] = new char[3];
		}
	}
	secarr = new char* [3];
	for (int i = 0; i < 3;i++) {
		secarr[i] = new char[3];
	}	
}
TicTacToe::~TicTacToe() {

}
void TicTacToe::Print() {
	cout << "Lower game:" << endl;	
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cout << tp[i][j][k] << "|";
				
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "Upper game:"<<endl;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
			
				cout << secarr[j][k] << "|";
			}
			cout << endl;
		}
		
	

}
void TicTacToe::GetMove(bool& winner,bool& winner2,bool& draw,bool& upperdraw,int row,int column,int &board) {
	bool flag = false;
	int prevrow=0;
	int prevcolumn=0;
	
	while (flag != true) {
		cout << "Enter X/O:" << endl;
		cin >> box;
		if (((previousmove == 'X' && box == 'X') || (previousmove == 'O' && box == 'O'))) {

			flag = false;
			cout << "Wrong turn!" << endl;


		}
		else if (tp[board][row][column] == 'X' || tp[board][row][column] == 'O') {
			flag = false;
			cout << "Already filled!" << endl;
			cout << "Enter row 0 to 2" << ":" << endl;
			cin >> row;
			cout << "Enter column 0 to 2" << ":" << endl;
			cin >> column;
		}
		else {
			flag = true;
		}
	}
	tp[board][row][column] = box;
	previousmove = box;

	
	winner = checkWinner(tp,box,row,column,board,draw);
	if (winner==true) {
		if (board == 0) {
			prevrow = 0;
			prevcolumn = 0;
		}
		else if (board == 1) {
			prevrow = 0;
			prevcolumn = 1;
		}
		else if (board==2) {
			prevrow = 0;
			prevcolumn = 2;
		}
		else if (board==3) {
			prevrow = 1;
			prevcolumn = 0;
		}
		else if (board==4) {
			prevrow = 1;
			prevcolumn = 1;
		}
		else if (board==5) {
			prevrow = 1;
			prevcolumn = 2;
		}
		else if (board==6) {
			prevrow = 2;
			prevcolumn = 0;
		}
		else if (board==7) {
			prevrow = 2;
			prevcolumn = 1;
		}
		else if (board==8) {
			prevrow = 2;
			prevcolumn = 2;
		}
		secarr[prevrow][prevcolumn] = box;
		upperbox = box;
		winner2=checkupperWinner(secarr,upperbox,prevrow,prevcolumn,upperdraw);
		if (winner2==true) {
			cout << "Congrats! Winner is " << upperbox<<endl;
		}
	}
	else if (draw==true) {
		if (board == 0) {
			prevrow = 0;
			prevcolumn = 0;
		}
		else if (board == 1) {
			prevrow = 0;
			prevcolumn = 1;
		}
		else if (board == 2) {
			prevrow = 0;
			prevcolumn = 2;
		}
		else if (board == 3) {
			prevrow = 1;
			prevcolumn = 0;
		}
		else if (board == 4) {
			prevrow = 1;
			prevcolumn = 1;
		}
		else if (board == 5) {
			prevrow = 1;
			prevcolumn = 2;
		}
		else if (board == 6) {
			prevrow = 2;
			prevcolumn = 0;
		}
		else if (board == 7) {
			prevrow = 2;
			prevcolumn = 1;
		}
		else if (board == 8) {
			prevrow = 2;
			prevcolumn = 2;
		}
		secarr[prevrow][prevcolumn] = 'D';
		upperbox = 'D';
		winner2 = checkupperWinner(secarr, upperbox, prevrow, prevcolumn, upperdraw);
		if (winner2 == true) {
			cout << "Congrats! Winner is " << upperbox<<endl;
		}
	}
	if (row == 0 && column == 0) {
		board = 0;
	}
	else if (row == 0 && column == 1) {
		board = 1;
	}
	else if (row == 0 && column == 2) {
		board = 2;
	}
	else if (row == 1 && column == 0) {
		board = 3;
	}
	else if (row == 1 && column == 1) {
		board = 4;
	}
	else if (row == 1 && column == 2) {
		board = 5;
	}
	else if (row == 2 && column == 0) {
		board = 6;
	}
	else if (row == 2 && column == 1) {
		board = 7;
	}
	else if (row == 2 && column == 2) {
		board = 8;
	}



}
bool TicTacToe::checkWinner(char***& tp, char box, int row, int column,int &board,bool& draw) {
	
	bool flag = false;
	for (int k = 0; k < 3; k++) {
		if (tp[board][row][k] == box) {
			flag = true;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag == false) {
		for (int l = 0; l < 3; l++) {
			if (tp[board][l][column] == box) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (flag == false) {
		for (int i = 0; i < 3; i++) {
			if (tp[board][i][i] == box) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (flag==false) {
		for (int i = 2, j=0; i >= 0;i--,j++) {
			if (tp[board][j][i]==box) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	bool allfilled1 = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tp[board][i][j] == 'X' || secarr[i][j] == 'O') {
				allfilled1 = true;
			}
			else {
				allfilled1 = false;
				break;
			}
		}
	}
	if (allfilled1 == true && flag == false) {
		draw = true;
				
	}
	if (flag == true) {
		return flag;
	}
	else {
		return false;
	}

}
bool TicTacToe::checkupperWinner(char **&secarr,char upperbox,int prevrow,int prevcolumn,bool& upperdraw) {
	bool flag2 = false;
	for (int k = 0; k < 3; k++) {
		if (secarr[prevrow][k] == upperbox) {
			flag2 = true;
		}
		else {
			flag2 = false;
			break;
		}
	}
	
	if (flag2 == false) {
		for (int l = 0; l < 3; l++) {
			if (secarr[l][prevcolumn] == upperbox) {
				flag2 = true;
			}
			else {
				flag2 = false;
				break;
			}
		}
	}
	
	if (flag2 == false) {
		for (int i = 0; i < 3; i++) {
			if (secarr[i][i] == upperbox) {
				flag2 = true;
			}
			else {
				flag2 = false;
				break;
			}
		}
	}
	
	if (flag2 == false) {
		for (int i = 2, j = 0; i >= 0; i--, j++) {
			if (secarr[j][i] == upperbox) {
				flag2 = true;
			}
			else {
				flag2 = false;
				break;
			}
		}
	}
	
		bool allfilled = false;
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				if (secarr[i][j]=='X'|| secarr[i][j]=='O') {
					allfilled = true;
				}
				else {
					allfilled = false;
					break;
				}
			}
		}
		if (allfilled == true && flag2==false) {
			upperdraw = true;
			cout << "UPPER GAME IS A DRAW!" << endl;
		}
		
	if (flag2 == true) {
		return flag2;
	}
	else {
		return false;
	}
}



