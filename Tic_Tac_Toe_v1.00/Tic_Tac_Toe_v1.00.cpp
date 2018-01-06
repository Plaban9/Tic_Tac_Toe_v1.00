// Tic_Tac_Toe_v1.00.cpp : Defines the entry point for the console application.
//Created by Plaban Biswas

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "graphics.h"
//#include "rlutil.h"
//#include <Wingdi.h>

using namespace std;

char board_matrix[3][3] = { { ' ', ' ', ' '}, { ' ', ' ', ' '}, { ' ', ' ', ' '} };

void display_board();
void validate_coordinate(int row, int column, char player);
void character_color(int row, int column);
bool row_check(char player);
bool column_check(char player);
bool diagonal_check(char player);
bool left_diagonal_check(char player);
bool right_diagonal_check(char player);
int win_check(char player);


int main()
{
	string	player_x, player_o;
	int over_flag = 0, move_counter = 0, row, column;
	
	cout << "\n Enter player name for 'X' : ";
	cin >> player_x;
	cout << "\n Enter player name for 'O' : ";
	cin >> player_o;

	while (over_flag == 0)
	{
		display_board();

		if (move_counter % 2 == 0)
		{
			cout << "\n " << player_x << "'s chance!!";
			cout << "\n Enter coordinates: ";
			cout << "\n Row no. : ";
			cin >> row;
			cout << " Column no. : ";
			cin >> column;
			validate_coordinate(row, column, 'X');
			
			display_board();

			if (move_counter >= 4)
			{
				switch (win_check('X'))
				{
				case 1: cout << "\n " << player_x << " wins by stricking out a row !!\n";
					over_flag = 1;
					break;
				
				case 2: cout << "\n " << player_x << " wins by stricking out a column !!\n";
					over_flag = 1;
					break;

				case 3: cout << "\n " << player_x << " wins by stricking out a diagonal !!\n";
					over_flag = 1;
					break;
				}
			}
		}

		else
		{
			cout << "\n " << player_o << "'s chance!!";
			cout << "\n Enter coordinates: ";
			cout << "\n Row no. : ";
			cin >> row;
			cout << " Column no. : ";
			cin >> column;
			validate_coordinate(row, column, 'O');

			display_board();

			if (move_counter >= 5)
			{
				switch (win_check('O'))
				{
					case 1: cout << "\n " << player_o << " wins by stricking out a row !!\n";
						over_flag = 1;
						break;

					case 2: cout << "\n " << player_o << " wins by stricking out a column !!\n";
						over_flag = 1;
						break;

					case 3: cout << "\n " << player_o << " wins by stricking out a diagonal !!\n";
						over_flag = 1;
						break;
				}
			}
		}

		move_counter++;
		
		if (move_counter == 9 && over_flag == 0)
		{
			//check for match draw condition
			over_flag = 1;

			cout << "\nMatch Drawn!!\n";
		}

	}
		
    return 0;
}// End_Of_Main


void display_board()
{
	system("cls");

	cout << "\n**********************";
	cout << "\n***TIC-TAC-TOE GAME***";
	cout << "\n**********************\n";
	cout << "\n        |       |    \n";
	cout << "     "; 
	character_color(0, 0);
	cout << "  |   ";
	character_color(0, 1);
	cout << "   |  ";
	character_color(0, 2);
	cout << "\n";
	cout << "        |       |    \n";
	cout << "  ---------------------\n";
	cout << "        |       |    \n";
	cout << "     ";
	character_color(1, 0);
	cout << "  |   ";
	character_color(1, 1);
	cout << "   |  ";
	character_color(1, 2);
	cout << "\n";
	cout << "        |       |    \n";
	cout << "  ---------------------\n";
	cout << "        |       |    \n";
	cout << "     ";
	character_color(2, 0);
	cout << "  |   ";
	character_color(2, 1);
	cout << "   |  ";
	character_color(2, 2);
	cout << "\n";
	cout << "        |       |    \n";

	/*
	cout << "\n**********************";
	cout << "\n***TIC-TAC-TOE GAME***";
	cout << "\n**********************\n";
	cout << "\n        |       |    \n";
	cout << "     " << board_matrix[0][0] << "  |   " << board_matrix[0][1] << "   |  " << board_matrix[0][2] << "\n";
	cout << "        |       |    \n";
	cout << "  ---------------------\n";
	cout << "        |       |    \n";
	cout << "     " << board_matrix[1][0] << "  |   " << board_matrix[1][1] << "   |  " << board_matrix[1][2] << "\n";
	cout << "        |       |    \n";
	cout << "  ---------------------\n";
	cout << "        |       |    \n";
	cout << "     " << board_matrix[2][0] << "  |   " << board_matrix[2][1] << "   |  " << board_matrix[2][2] << "\n";
	cout << "        |       |    \n";
	*/
	/*for (int i = 0; i < 3; ++i)
	{
		cout << "\n ";

		for (int j = 0; j < 3; ++j)			
			cout << board_matrix[i][j] <<" ";
		

	}*/
	
}//End_Of_Display_Board

void character_color(int row, int column)
{
	if (board_matrix[row][column] == 'X')
	{
		setfontcolor(3);
		//	SetTextColor();
		system("color 0B");
		//rlutil::setColor(2);
		cout << board_matrix[row][column];
		//system("color 07");
	}

	else if (board_matrix[row][column] == 'O')
	{
		setcolor(2);
		system("color 0C");
		cout << board_matrix[row][column];
		//system("color 07");
	}

	else
		cout << board_matrix[row][column];
}

void validate_coordinate(int row, int column, char player)
{
	int flag = 0;
		
	do
	{
		if ((row > 3 || row < 1) || (column > 3 || column < 1))
		{
			flag = 0;

			cout << "\n Invalid Coordinates!!  Coordinates out of range.";
			cout << "\n Enter coordintes again!";
			cout << "\n Row no. : ";
			cin >> row;
			cout << " Column no. : ";
			cin >> column;
		}

		else if (board_matrix[row - 1][column - 1] == ' ')
		{
			flag = 1;
			board_matrix[row - 1][column - 1] = player;
		}

		else
		{
			flag = 0;
		
			cout << "\n Invalid Coordinates!! Coordinate already occupied by " << board_matrix[row-1][column-1];
			cout << "\n Enter coordintes again!";
			cout << "\n Row no. : ";
			cin >> row;
			cout << " Column no. : ";
			cin >> column;
		}

	} while(flag==0);

}//End_Of_Validate_coordinate

int win_check(char player)
{
	if (row_check(player))
		return 1;

	else if (column_check(player))
		return 2;

	else if (diagonal_check(player))
		return 3;
	
	else
		return 0;

}//End_of_Win_Check

bool row_check(char player)
{
	for (int i = 0; i < 3; i++)
		if ((board_matrix[i][0] == player) && (board_matrix[i][1] == player) && (board_matrix[i][2] == player))
			return true;

	return false;
}//End_row_check

bool column_check(char player)
{
	for (int i = 0; i < 3; i++)
		if ((board_matrix[0][i] == player) && (board_matrix[1][i] == player) && (board_matrix[2][i] == player))
			return true;

	return false;
}//End_of_column_check

bool diagonal_check(char player)
{
	for (int i = 0; i < 3; i++)
		if (left_diagonal_check(player) || right_diagonal_check(player))
			return true;

	return false;
}//End_of_diagonal_check

bool left_diagonal_check(char player)
{
	if ((board_matrix[0][0] == player) && (board_matrix[1][1] == player) && (board_matrix[2][2] == player))
		return true;

	return false;
}//End_of_left_diagonal_check

bool right_diagonal_check(char player)
{
	if ((board_matrix[0][2] == player) && (board_matrix[1][1] == player) && (board_matrix[2][0] == player))
		return true;

	return false;
}//End_of_right_diagonal_check