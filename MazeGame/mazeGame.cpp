#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#define max 100
using namespace std;
char entry;
void XY(int x, int y);
void move(int lab[][max], int size);
void map(int lab[][max], int size);
int main()
{
	int lab[max][max];
	int size;
	int i, j;
	remove("hareket.txt");
	cout << "                              ********* WELCOME TO THE MAZE GAME ********               " << endl;
	cout << " ENTER THE SIZE OF MAZE :";
	srand(time(NULL));
	cin >> size;
	system("color F");
	map(lab, size);
	move(lab, size);
	_getch();
	system("pause");
	return 0;
}
void map(int lab[][max], int size)
{
	int i, j;
	lab[-1][1] = 1;
	lab[0][1] = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			lab[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 1 || i == size - 2)
			{
				lab[i][j] = 0;
			}
			if (i == 0 || i == size - 1)
			{
				lab[i][j] = 1;
			}
			if (j == 0 || j == size - 1)
			{
				lab[i][j] = 1;
			}
		}
	}
	for (j = 1; j < size / 2; j++)
	{
		lab[size / 5][j] = 0;
	}
	for (j = 1; j < size / 2; j++)
	{
		lab[size / 8][j] = 0;
	}
	for (i = 1; i < size / 2; i++)
	{
		lab[i][size / 2] = 0;
	}
	for (i = size / 2; i < (size / 3) * 2; i++)
	{
		lab[i][size / 7] = 0;
	}
	for (i = size / 2; i < (size / 3) * 2; i++)
	{
		lab[i][(size / 3) * 2] = 0;

	}
	for (j = 1; j < size - 1; j++)
	{
		lab[size / 2][j] = 0;
	}
	for (j = 1; j < size / 3; j++)
	{
		lab[size / size][j] = 0;
	}
	for (i = size / 7; i < size / 2; i++)
	{
		lab[i][size / 5] = 0;
	}
	for (j = size / 3; j < 2 * (size / 3); j++)
	{
		lab[2 * size / 5][j] = 0;
	}
	for (i = size / 2; i < size - 1; i++)
	{
		lab[i][(size / 5) * 3] = 0;
		lab[i][(size / 5) * 3] = 3;
	}
	for (j = (size / 3) * 2; j < size / 5 * 4; j++)
	{
		lab[(size / 5) * 4][j] = 0;
	}
	for (i = size / 2; i < size - 1; i++)
	{
		lab[i][(size / 8)] = 0;

	}
	for (i = (size / 5); i < size - 1; i++)
	{
		lab[i][(size / 5) * 4] = 0;

	}
	int k = 0;
	while (true)
	{
		int x = rand() % size;
		int y = rand() % size;
		if (lab[x][y] == 0)
		{
			lab[x][y] = 3;
			k++;
		}
		if (k == size / 2)
			break;
	}
	int c = 0;
	while (true)
	{
		int a = rand() % size;
		int b = rand() % size;
		if (lab[a][b] == 1 && a != 0 && b != 0 && a != size - 1 && b != size - 1)
		{
			lab[a][b] = 4;
			c++;
		}
		if (c == size / 4)
			break;
	}
	lab[0][1] = 0;
	lab[size - 1][size - 2] = 2;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (lab[i][j] == 0)
			{
				cout << " ";
			}
			if (lab[i][j] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "$";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			if (lab[i][j] == 2)
			{
				cout << " ";
			}
			if (lab[i][j] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "*";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			if (lab[i][j] == 1)
			{
				cout << char(219);
			}
		}
		cout << endl;
	}
}
void XY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
ofstream coordinates;
void move(int lab[][max], int size)
{
	cout << endl << endl;
	cout << " Use W,A,S,D To Move!" << endl;
	cout << " $ IS A GOLD" << endl << " * IS A MONSTER " << endl;

	int x = 1;
	int y = 0;
	int xCln = 1;
	int yCln = 0;
	int gold = 0;

	coordinates.open("hareket.txt", ios_base::app);
	while (true)
	{
		XY(xCln, yCln);
		cout << " ";
		XY(x, y);
		cout << char(175);
		entry = _getch();
		xCln = x;
		yCln = y;

		if (entry == 'w' || entry == 'W')
		{
			y -= 1;
			coordinates << y << "," << x << "\n";

		}
		if (entry == 's' || entry == 'S')
		{
			y += 1;
			coordinates << y << "," << x << "\n";
		}
		if (entry == 'a' || entry == 'A')
		{
			x -= 1;
			coordinates << y << "," << x << "\n";
		}
		if (entry == 'd' || entry == 'D')
		{
			x += 1;
			coordinates << y << "," << x << "\n";
		}
		if (lab[y][x] == 1)
		{
			x = xCln;
			y = yCln;
		}
		if (lab[y][x] == 3)
		{
			lab[y][x] = 0;
			gold++;
		}
		if (lab[y][x] == 4)
		{
			x = 1;
			y = 0;
			gold = 0;
		}
		if (lab[y][x] == 2)
		{
			system("cls");
			cout << endl;
			system("color E");
			cout << "                *****************************************************************             " << endl;
			cout << "Congratulations , You Win !!!" << endl;
			cout << endl;
			cout << "TOTAL OF GOLDS : " << gold << endl;
			cout << endl;
			coordinates.close();
			break;
		}
	}
}

