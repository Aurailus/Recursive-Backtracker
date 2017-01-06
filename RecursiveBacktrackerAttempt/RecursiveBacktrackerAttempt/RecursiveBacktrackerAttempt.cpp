#include "stdafx.h"
#include <iostream>
#include <chrono>  //for pausing
#include <thread>  //for pausing
#include <cstdlib> //random values
#include <vector>  //backtracking
#include <conio.h>

using namespace std;

int main()
{
	srand(time(NULL)); //init random seed
	const int mapWidth = 20, mapHeight = 10;

	char sideBorder[mapHeight][mapWidth], bottomBorder[mapHeight][mapWidth], tiles[mapHeight][mapWidth];
	char playerChar = '@', discoveredChar = '.', undiscoveredChar = '#';
	int x = 10, y = 5;
	vector<int> xhistory(1, x);
	vector<int> yhistory(1, y);
    
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			sideBorder[i][j] = '|';
			bottomBorder[i][j] = '-';
			tiles[i][j] = undiscoveredChar;
			
		}
	}

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(350)); //pause to account for CMD visual stutter

		tiles[y][x] = discoveredChar;

		bool right = false, left = false, top = false, bottom = false;

		if (x < mapWidth - 1) if (tiles[y][x + 1] == undiscoveredChar) { right = true; }   //find if there's undiscovered tiles
		if (y < mapHeight - 1) if (tiles[y + 1][x] == undiscoveredChar) { bottom = true; } //and then set the boolean to the
		if (x > 0) if (tiles[y][x - 1] == undiscoveredChar) { left = true; }               //correct value
		if (y > 0) if (tiles[y - 1][x] == undiscoveredChar) { top = true; }

		if (top == true || left == true || bottom == true || right == true) {
			bool moved = false;
			do {
				int dir = rand() %  4; //value from 0 - 3
				switch (dir)
				{
				case 0:
					if (right == true)
					{
						x++;
						sideBorder[y][x-1] = ' ';
						moved = true;
					}
					break;
				case 1:
					if (bottom == true)
					{
						y++;
						bottomBorder[y-1][x] = ' ';
						moved = true;
					}
					break;
				case 2:
					if (left == true)
					{
						x--;
						sideBorder[y][x] = ' ';
						moved = true;
					}
					break;
				case 3:
					if (top == true)
					{
						y--;
						bottomBorder[y][x] = ' ';
						moved = true;
					}
					break;
				}
			} while (moved == false);

			xhistory.push_back(x);
			yhistory.push_back(y);
		}
		else
		{
			x = xhistory.back();
			y = yhistory.back();
			xhistory.pop_back();
			yhistory.pop_back();
		}

		system("cls");

		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl; //top border visual fix
		for (int i = 0; i < mapHeight; i++) //display board
		{
			cout << "|"; //left border visual fix
			for (int j = 0; j < mapWidth; j++)
			{
				if (x == j && i == y) cout << playerChar; //display current tile
				else cout << tiles[i][j]; //else display tile state

				cout << sideBorder[i][j];
			}
			cout << endl << "*"; //left border visual fix
			for (int j = 0; j < mapWidth; j++)
			{
				cout << bottomBorder[i][j] << "*";
			}
			cout << endl;
		}
	}
}