#include<iostream>
#include<fstream>
#include<windows.h>
#include"TicTacToe.h"

using namespace std;

char grid[3][3] = {	' ', ' ', ' ', 
					' ', ' ', ' ', 
					' ', ' ', ' '};


int main()
{
	
	int  PosX, PosY;
	char again;
	
	system("color 3F");
	
	cout << "\n\n " << endl;
	cout << "\t\t Loading.";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	
	system("cls");

	playagain: 
		TicTacToe Game;
		int  DrawCheck = 0;
		
		
		Game.RefreshGrid();
		Game.Output();
	
	do
	{
		
		cout << "\nEnter Position for (O)Player1 (eg. 1 2): ";
		cin  >> PosX >> PosY;
		
		Game.InputPosP1(PosX, PosY);
		DrawCheck++;
		
		system("cls");
		
		Game.Output();
		if(Game.CheckVictory() == true)
		{
			Game.P1Score++;
			break;
		}
		
		if(DrawCheck == 9)
		{
			cout << " *** Game Ended with a Draw *** " << endl;
			break;
		}
		
		
		cout << "\nEnter Position for (X)Player2 (eg. 1 2): ";
		cin  >> PosX >> PosY;
		
		Game.InputPosP2(PosX, PosY);
		DrawCheck++;
		
		system("cls");
		
		Game.Output();
		if(Game.CheckVictory() == true)
		{
			Game.P2Score++;
			break;
		}
		
		if(DrawCheck == 9)
		{
			cout << " *** Game Ended with a Draw *** " << endl;
			break;
		}
		
	}while(1);
	
	Game.ShowScore();
	
	cout << "Do you want to Play Again ? " << endl;
	cout << "Enter Y to play again: ";
	cin  >> again;
	
	if(again == 'Y' || again == 'y')
	{
		system("cls");
		goto playagain;
	}
	else
	{
		Game.SaveScore();
		
		cout << "\n\n";
		system("cls");
		
		cout << "\t\t Thank You For Playing...." << endl;
		cout << endl;
		cout << "\t\t          *** DEVELOPERS *** "      		<< endl;
		cout << "\t\t Muhammad Anas           BSEM-F19-190 " 	<< endl;
		cout << "\t\t Muhammad Muneeb Saleem  BSEM-F19-072 " 	<< endl;
		cout << "\t\t Rasikh Ali              BSEM-F19-060 "	<< endl;
	}
	
	
	
}
