#pragma once

class TicTacToe {
	int board = 0;
	char box = '\0';
	char upperbox = '\0';
	int result = 0;
	char*** tp;
	char** secarr;
	char previousmove = '\0';
public:
	TicTacToe();
	
	~TicTacToe();
	void Print();
	void GetMove(bool& winner,bool &winner2,bool& draw,bool& upperdraw,int row,int column,int &board);
	bool checkWinner(char***& tp, char box, int row, int column,int &board,bool& draw);
	bool checkupperWinner(char**&secarr,char upperbox,int row,int column,bool& upperdraw);


};

