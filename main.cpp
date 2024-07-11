#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
bool gameOver;

const int width = 20;
const int height = 20;
int score;
int x, y, fruitX, fruitY;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void SetUp() 
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coord);

	for (int i = 0; i < width + 2; i++)
		cout << '#';
	cout << endl;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width+2; j++)
		{
			if (j == 0 || j == width + 1)
				cout << '#';
			else if (i == y && j == x)
				cout << 'O';
			else if (i == fruitY && j == fruitX)
				cout << 'F';
			else
				cout << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++)
		cout << '#';
	cout << endl;

	cout << "Score: " << score << endl;
}

void Input() 
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x < 0 || x > width || y < 0 || y > height)
	{
		gameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main() 
{
	SetUp();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(100);
	}
}