#include<iostream>
#include"UTTT.h"
using namespace std;

int main() {
	TicTacToe p;
	bool winner = false;
	bool winner2 = false;
	bool draw = false;
	bool upperdraw = false;
	p.Print();
	cout << "Pick a board from 0-8" << endl;
	int board = 0;
	cin >> board;
	int row = 0;
	int column = 0;
	while (winner2 != true && upperdraw==false) {
	cout << "Enter row from 0 to 2:" << endl;
	cin >> row;
	cout << "Enter column from 0 to 2:" << endl;
	cin >> column;
	
	p.GetMove(winner, winner2,draw,upperdraw, row, column, board);
	p.Print();
}
	system("pause");
}