#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	const int mapWidth = 20, mapHeight = 10;

	char topBorder[mapHeight][mapWidth];
	char rightBorder[mapHeight][mapWidth];
	char bottomBorder[mapHeight][mapWidth];
	char leftBorder[mapHeight][mapWidth];
	char tiles[mapHeight][mapWidth];
    
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			topBorder[i][j] = '_';
			rightBorder[i][j] = '|';
			bottomBorder[i][j] = '_';
			leftBorder[i][j] = '|';
			tiles[i][j] = '0';
		}
	}

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");

		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				cout << "." << topBorder[i][j] << ".";
			}
			cout << endl;
			for (int j = 0; j < mapWidth; j++)
			{
				cout << leftBorder[i][j] << tiles[i][j] << rightBorder[i][j];
			}
			cout << endl;
			for (int j = 0; j < mapWidth; j++)
			{
				cout << "." << bottomBorder[i][j] << ".";
			}
			cout << endl;
		}
	}
}

