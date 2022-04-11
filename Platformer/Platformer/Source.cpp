#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool gameOver;
const int width = 237;
const int height = 20;
int x, y, destructorY, destructorX, score, finishY, finishX;
enum eDirection {STOP = 0, LEFT, RIGHT, UP};
eDirection dir;
void Setup() {
	gameOver = false;
	dir = STOP;
	x = 1;
	y = 19;
	srand(time(NULL));
	destructorY = 19;
	destructorX = rand() % (50+x);
	finishY = 19;
	finishX = width - 10;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0);// represents left most border
			else if (i == destructorY && j == destructorX) cout << "M";
			else if (i == y && j == x) cout << "O";
			else if (i == finishY && j == finishX) cout << "P";
			else {
				bool print = false;
				if (!print) cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	
	cout << endl;
}

void Logic() {
	switch (dir) {
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	case UP:
		y--;
		break;
	case STOP:
		x = x;
		break;
	}
	if (x > finishX && y == finishY) {
		gameOver = true;
		cout << endl << "Winner! Winner! Chicken Dinner!";
	}
	if (x == destructorX && y == destructorY) {
		gameOver = true;
	}
	if (x > destructorX && y == destructorY) {
		destructorX = rand() % (50+x);
	}
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'd':
			dir = RIGHT;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = STOP;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		if (dir == UP) {
			for (int i = y; i < 19; i++) {
				y++;
				x = x + 2;
				dir = RIGHT;
			}
		}
		Input();
		Logic();
		Sleep(30);
	}
	return 0;
}