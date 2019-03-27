#include <iostream>
#include<fstream>
#include <string>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
} 
string Matrix[8][8];
string Player1Name, Player2Name;
int win1_Count = 0,win2_Count = 0, tie_Count = 0, player1_Score = 0, player2_Score = 0, Rounds = 1, tieCount=0 ;

void setNames();
void FillMatrix();
void PrintMatrix();
void gameOperation();
void Player1Drop();
int check_For_Win1(string);
void history();
void Player2Drop();
int check_For_Win2(string);

void main()
{
	setNames();
	FillMatrix();
	PrintMatrix();
	gameOperation();
}

void setNames()
{
	cout << "Enter player1 name: ";  cin >> Player1Name;
	cout << "Enter player2 name: ";  cin >> Player2Name;
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t*************************************************************\n";
	cout << "\t*************** Wellcome To CONNECT FOUR Game ***************\n";
	cout << "\t*************************************************************\n";
	Sleep(2000);
}

void FillMatrix()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Matrix[i][j] = "|_|";
		}
	}
}

void PrintMatrix()
{
	system("cls");
	cout << "Enter a number between 1:8 " << endl;
	cout << " 1   2   3   4   5   6   7   8" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Player1Drop()
{
	cout << Player1Name << " : ";
	int Player1_drop;
	while (true)
	{
		int col_full = 0;
		cplayer2: cin.clear();
		cin.ignore(10000, '\n');
		cin >> Player1_drop;
		if (Player1_drop < 1 || Player1_drop > 8)
		{
			cout << "Please enter a number between 1:8 " << endl;
			continue;
		}
		
		else if(Player1_drop > 0 || Player1_drop < 9)
		{
			for (int i = 7; i >= 0; i--)
			{
				if (Matrix[i][Player1_drop - 1] == "|_|")
				{
					Matrix[i][Player1_drop - 1] = "|0|";
					tie_Count++;
					break;
				}
				else
				{
					col_full++;
				}
			}
		}
		else {
			cout << "Please enter a number between 1:8" << endl;
			goto cplayer2;
		}
		if (col_full == 8)
		{
			cout << "The column is Full !! Please enter another column number " << endl;
			continue;
		}
		break;
	}
}

void Player2Drop()
{
	int Player2_drop;
	cout << Player2Name << " : ";
	while (true)
	{
		int col_full = 0;
		cplayer2: cin.clear();
		cin.ignore(10000, '\n');
		cin >> Player2_drop;
		if (Player2_drop < 1 || Player2_drop > 8)
		{
			cout << "Please enter a number between 1:8 " << endl;
			continue;
		}
		else if(Player2_drop >0 || Player2_drop <9)
		{
			for (int i = 7; i >= 0; i--)
			{
				if (Matrix[i][Player2_drop - 1] == "|_|")
				{
					Matrix[i][Player2_drop - 1] = "|X|";
					tie_Count++;
					break;
				}
				else
				{
					col_full++;
				}
			}
		}
		else {
			cout << "Please enter a number between 1:8" << endl;
			goto cplayer2;
		}
		if (col_full == 8)
		{
			cout << "The column is Full !! Please enter another column number" << endl;
			continue;
		}
		break;
	}
}

int check_For_Win1(string str[8][8])
{
	for (int i = 7; i >= 0; i--)//Horizontal line test
	{
		if (str[i][0] == "|0|"&&str[i][1] == "|0|"&&str[i][2] == "|0|"&&str[i][3] == "|0|" || str[i][1] == "|0|"&&str[i][2] == "|0|"&&str[i][3] == "|0|"&&str[i][4] == "|0|" ||
			str[i][2] == "|0|"&&str[i][3] == "|0|"&&str[i][4] == "|0|"&&str[i][5] == "|0|" || str[i][3] == "|0|"&&str[i][4] == "|0|"&&str[i][5] == "|0|"&&str[i][6] == "|0|" ||
			str[i][4] == "|0|"&&str[i][5] == "|0|"&&str[i][6] == "|0|"&&str[i][7] == "|0|")
			win1_Count = 1;
	}
	for (int i = 7; i > 2; i--)//Diagonal test
	{//Right diagonal
		if (str[i][0] == "|0|"&&str[i - 1][1] == "|0|"&&str[i - 2][2] == "|0|"&&str[i - 3][3] == "|0|" || str[i][1] == "|0|"&&str[i - 1][2] == "|0|"&&str[i - 2][3] == "|0|"&&str[i - 3][4] == "|0|" ||
			str[i][2] == "|0|"&&str[i - 1][3] == "|0|"&&str[i - 2][4] == "|0|"&&str[i - 3][5] == "|0|" || str[i][3] == "|0|"&&str[i - 1][4] == "|0|"&&str[i - 2][5] == "|0|"&&str[i - 3][6] == "|0|" ||
			str[i][4] == "|0|"&&str[i - 1][5] == "|0|"&&str[i - 2][6] == "|0|"&&str[i - 3][7] == "|0|")
			win1_Count = 1;
		//Left diagonal
		if (str[i][7] == "|0|"&&str[i - 1][6] == "|0|"&&str[i - 2][5] == "|0|"&&str[i - 3][4] == "|0|" || str[i][6] == "|0|"&&str[i - 1][5] == "|0|"&&str[i - 2][4] == "|0|"&&str[i - 3][3] == "|0|" ||
			str[i][5] == "|0|"&&str[i - 1][4] == "|0|"&&str[i - 2][3] == "|0|"&&str[i - 3][2] == "|0|" || str[i][4] == "|0|"&&str[i - 1][3] == "|0|"&&str[i - 2][2] == "|0|"&&str[i - 3][1] == "|0|" ||
			str[i][3] == "|0|"&&str[i - 1][2] == "|0|"&&str[i - 2][1] == "|0|"&&str[i - 3][0] == "|0|")
			win1_Count = 1;
		//Vertical test
		if (str[i][0] == "|0|"&&str[i - 1][0] == "|0|"&&str[i - 2][0] == "|0|"&&str[i - 3][0] == "|0|" || str[i][1] == "|0|"&&str[i - 1][1] == "|0|"&&str[i - 2][1] == "|0|"&&str[i - 3][1] == "|0|" ||
			str[i][2] == "|0|"&&str[i - 1][2] == "|0|"&&str[i - 2][2] == "|0|"&&str[i - 3][2] == "|0|" || str[i][3] == "|0|"&&str[i - 1][3] == "|0|"&&str[i - 2][3] == "|0|"&&str[i - 3][3] == "|0|" ||
			str[i][4] == "|0|"&&str[i - 1][4] == "|0|"&&str[i - 2][4] == "|0|"&&str[i - 3][4] == "|0|" || str[i][5] == "|0|"&&str[i - 1][5] == "|0|"&&str[i - 2][5] == "|0|"&&str[i - 3][5] == "|0|" ||
			str[i][6] == "|0|"&&str[i - 1][6] == "|0|"&&str[i - 2][6] == "|0|"&&str[i - 3][6] == "|0|" || str[i][7] == "|0|"&&str[i - 1][7] == "|0|"&&str[i - 2][7] == "|0|"&&str[i - 3][7] == "|0|")
			win1_Count = 1;
	}
	return win1_Count;
}

int check_For_Win2(string str[8][8])
{
	for (int i = 7; i >= 0; i--)//Horizontal line test
	{
		if (str[i][0] == "|X|"&&str[i][1] == "|X|"&&str[i][2] == "|X|"&&str[i][3] == "|X|" || str[i][1] == "|X|"&&str[i][2] == "|X|"&&str[i][3] == "|X|"&&str[i][4] == "|X|" ||
			str[i][2] == "|X|"&&str[i][3] == "|X|"&&str[i][4] == "|X|"&&str[i][5] == "|X|" || str[i][3] == "|X|"&&str[i][4] == "|X|"&&str[i][5] == "|X|"&&str[i][6] == "|X|" ||
			str[i][4] == "|X|"&&str[i][5] == "|X|"&&str[i][6] == "|X|"&&str[i][7] == "|X|")
			win2_Count = 1;
	}
	for (int i = 7; i > 2; i--)//Diagonal test
	{//Right diagonal
		if (str[i][0] == "|X|"&&str[i - 1][1] == "|X|"&&str[i - 2][2] == "|X|"&&str[i - 3][3] == "|X|" || str[i][1] == "|X|"&&str[i - 1][2] == "|X|"&&str[i - 2][3] == "|X|"&&str[i - 3][4] == "|X|" ||
			str[i][2] == "|X|"&&str[i - 1][3] == "|X|"&&str[i - 2][4] == "|X|"&&str[i - 3][5] == "|X|" || str[i][3] == "|X|"&&str[i - 1][4] == "|X|"&&str[i - 2][5] == "|X|"&&str[i - 3][6] == "|X|" ||
			str[i][4] == "|X|"&&str[i - 1][5] == "|X|"&&str[i - 2][6] == "|X|"&&str[i - 3][7] == "|X|")
			win2_Count = 1;
		//Left diagonal
		if (str[i][7] == "|X|"&&str[i - 1][6] == "|X|"&&str[i - 2][5] == "|X|"&&str[i - 3][4] == "|X|" || str[i][6] == "|X|"&&str[i - 1][5] == "|X|"&&str[i - 2][4] == "|X|"&&str[i - 3][3] == "|X|" ||
			str[i][5] == "|X|"&&str[i - 1][4] == "|X|"&&str[i - 2][3] == "|X|"&&str[i - 3][2] == "|X|" || str[i][4] == "|X|"&&str[i - 1][3] == "|X|"&&str[i - 2][2] == "|X|"&&str[i - 3][1] == "|X|" ||
			str[i][3] == "|X|"&&str[i - 1][2] == "|X|"&&str[i - 2][1] == "|X|"&&str[i - 3][0] == "|X|")
			win2_Count = 1;
		//Vertical test
		if (str[i][0] == "|X|"&&str[i - 1][0] == "|X|"&&str[i - 2][0] == "|X|"&&str[i - 3][0] == "|X|" || str[i][1] == "|X|"&&str[i - 1][1] == "|X|"&&str[i - 2][1] == "|X|"&&str[i - 3][1] == "|X|" ||
			str[i][2] == "|X|"&&str[i - 1][2] == "|X|"&&str[i - 2][2] == "|X|"&&str[i - 3][2] == "|X|" || str[i][3] == "|X|"&&str[i - 1][3] == "|X|"&&str[i - 2][3] == "|X|"&&str[i - 3][3] == "|X|" ||
			str[i][4] == "|X|"&&str[i - 1][4] == "|X|"&&str[i - 2][4] == "|X|"&&str[i - 3][4] == "|X|" || str[i][5] == "|X|"&&str[i - 1][5] == "|X|"&&str[i - 2][5] == "|X|"&&str[i - 3][5] == "|X|" ||
			str[i][6] == "|X|"&&str[i - 1][6] == "|X|"&&str[i - 2][6] == "|X|"&&str[i - 3][6] == "|X|" || str[i][7] == "|X|"&&str[i - 1][7] == "|X|"&&str[i - 2][7] == "|X|"&&str[i - 3][7] == "|X|")
			win2_Count = 1;
	}
	return win2_Count;
}

void history() {
	fstream game_Scoreboard;
	game_Scoreboard.open("historyOfGames.text", fstream::in | fstream::out | fstream::app);

	game_Scoreboard << "Date and time: " << currentDateTime() << endl;
	game_Scoreboard << "You have played: "<< Rounds << " Rounds." << endl;
	game_Scoreboard << Player1Name << " Won " << player1_Score << " times." << endl;
	game_Scoreboard << Player2Name << " Won " << player2_Score << " times." << endl;
	game_Scoreboard << "Tied " << tieCount << " times." << endl ;
	if (player1_Score>player2_Score){
		game_Scoreboard << Player1Name << " is the winner of this game." << endl << endl << endl;
	}
	else if (player1_Score<player2_Score){
		game_Scoreboard << Player2Name << " is the winner of this game." << endl << endl << endl;
	}
	else
		game_Scoreboard << "It's a tie." << endl << endl << endl;

	game_Scoreboard.close();
}

void gameOperation() { 
	char again;
	while (1)
	{
		Player1Drop();
		PrintMatrix();
		win1_Count = check_For_Win1(Matrix);
		
		if (win1_Count == 1)
		{	
			player1_Score++;
			cout << Player1Name << " wins. \n";
			cout << " you wanna play agian (y/n) ? \n";
			again1: cin.clear();
			cin.ignore(10000, '\n');
			cin >> again;
		
			if (again == 'y' || again == 'Y')
			{
				Rounds++;
				win1_Count = 0;
				FillMatrix();
				PrintMatrix();
				continue;
			}

			else if (again == 'n' || again == 'N')
			{
				history();
				break;
			}
			else 
				goto again1;
		}
		Player2Drop();
		PrintMatrix();
		win2_Count = check_For_Win2(Matrix);
		if (win2_Count == 1)
		{
			player2_Score++;
			cout << Player2Name << " wins. \n";
			cout << " You want to play again (y/n) ? \n";
			again2: cin.clear();
			cin.ignore(10000, '\n');
			cin >> again;
			
			if (again == 'y' || again == 'Y')
			{

				Rounds++;
				win2_Count = 0;
				FillMatrix();
				PrintMatrix();
				continue;
			}

			else if (again == 'n' || again == 'N')
			{
				history();
				break;
			}
			else 
				goto again2;
		}
		if (tie_Count == 64)
		{
			cout << Player1Name << " and " << Player2Name << " are tied \n";
			tieCount++;
			cout << " You want to play again (y/n) ? \n";
			again3: cin.clear();
			cin.ignore(10000, '\n');
			cin >> again;

			tie_Count = 0;
			if (again == 'y' || again == 'Y')
			{
				Rounds++;

				win1_Count = 0;
				win2_Count = 0;
				FillMatrix();
				PrintMatrix();
				continue;
			}

			else if (again == 'n' || again == 'N')
			{
					history();
					break;
			}
			else 
				goto again3;
		}
	}
}

