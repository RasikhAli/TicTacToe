#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

char grid[3][3] = {	' ', ' ', ' ', 
					' ', ' ', ' ', 
					' ', ' ', ' '};

class TicTacToe
{
	public:
				   
		char player1 = 'O';
		int  P1Score = 0;
		
		char player2 = 'X';
		int  P2Score = 0;
		
		
		bool CheckVictory();
		bool CheckPos(int PosX, int PosY);
		void InputPosP1(int PosX, int PosY);
		void InputPosP2(int PosX, int PosY);
		void Output();
		void RefreshGrid();
		void ShowScore();
		void SaveScore();
		
};
				   
				   
bool TicTacToe::CheckVictory()
{
	int i = 0;
	int j = 0;
	
	int check = 0;
	
	// Check Vertical.
	if(grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j])
	{
		if(grid[i][j] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	else if(grid[i][j+1] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+1])
	{
		if(grid[i][j+1] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j+1] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	else if(grid[i][j+2] == grid[i+1][j+2] && grid[i+1][j+2] == grid[i+2][j+2])
	{
		if(grid[i][j+2] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j+2] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	
	// Check horizontal.
	if(grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2])
	{
		if(grid[i][j] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	else if(grid[i+1][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+1][j+2])
	{
		if(grid[i+1][j] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i+1][j] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	else if(grid[i+2][j] == grid[i+2][j+1] && grid[i+2][j+1] == grid[i+2][j+2])
	{
		if(grid[i+2][j] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i+2][j] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	
	
	// Check Diagonal.
	if(grid[i][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2])
	{
		if(grid[i][j] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	else if(grid[i][j+2] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j])
	{
		if(grid[i][j+2] == player1)
		{
			cout << "Player 1 won the game...";
			check = 1;
		}
		else if(grid[i][j+2] == player2)
		{
			cout << "Player 2 won the game...";
			check = 1;
		}
	}
	
	
	if(check == 1)
	{
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::CheckPos(int PosX, int PosY)
{
	if(grid[PosX-1][PosY-1] == player1 || grid[PosX-1][PosY-1] == player2)
	{
		cout << "Symbol Already Exists..." << endl;
		
		return true;
	}
	else
	{
		return false;		
	}
}

void TicTacToe::InputPosP1(int PosX, int PosY)
{
	
	if(PosX-1 < 0 || PosX-1 > 2 || PosY-1 < 0 || PosY-1 > 2)
	{
		cout << "Couldn't Exceed Grid Limit...." << endl;
		
		cout << "Enter Position for (O)Player1 (eg. 1 2): ";
		cin  >> PosX >> PosY;
		InputPosP1(PosX, PosY);
	}
	else
	{
		if(CheckPos(PosX, PosY) == false)
		{
			grid[PosX-1][PosY-1] = player1;
		}
		else
		{
			cout << "Enter Position for (O)Player1 (eg. 1 2): ";
			cin  >> PosX >> PosY;
			InputPosP1(PosX, PosY);
		}
	}
}

void TicTacToe::InputPosP2(int PosX, int PosY)
{
	if(PosX-1 < 0 || PosX-1 > 3 || PosY-1 < 0 || PosY-1 > 3)
	{
		cout << "Couldn't Exceed Grid Limit...." << endl;
		
		cout << "Enter Position for (X)Player2 (eg. 1 2): ";
		cin  >> PosX >> PosY;
		InputPosP2(PosX, PosY);
	}
	else
	{
		if(CheckPos(PosX, PosY) == false)
		{
			grid[PosX-1][PosY-1] = player2;
		}
		else
		{
			cout << "Enter Position for (X)Player2 (eg. 1 2): ";
			cin  >> PosX >> PosY;
			InputPosP2(PosX, PosY);
		}
	}
}

void TicTacToe::Output()
{
	cout << "\n\n\t **** TIC TAC TOE **** " << endl;
	cout << "\n\n" << endl;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(j == 0)
			{
				 cout << "\t\t";
			}
			
			if(j != 2)
			{
				cout << grid[i][j] << " | ";
			}
			else
			{
				cout << grid[i][j];
			}
			
			if(j == 2)
			{
				cout << endl;
				if(i != 2)
				{
					cout << "\t\t----------" << endl;
				}
			}
		}
	}
}

void TicTacToe::RefreshGrid()
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

void TicTacToe::ShowScore()
{
	cout << "\t\t\t P1 Score: " << P1Score;
	cout << " || ";
	cout << "P2 Score: " << P2Score;
	cout << endl << endl;
}

void TicTacToe::SaveScore()
{
	fstream outfile;
	outfile.open("scores.csv", ios::app);
	outfile << " P1 Score: " << ',' << P1Score << endl;
	outfile << " P2 Score: " << ',' << P2Score << endl;
	outfile << endl;
	
	outfile.close();
}
	
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
