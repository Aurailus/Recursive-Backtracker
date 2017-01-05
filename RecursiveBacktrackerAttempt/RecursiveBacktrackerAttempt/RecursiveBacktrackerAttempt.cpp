#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	const int mapWidth = 20, mapHeight = 10;

	char sideBorder[mapHeight][mapWidth];
	char bottomBorder[mapHeight][mapWidth];
	char tiles[mapHeight][mapWidth];
    
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			sideBorder[i][j] = '|';
			bottomBorder[i][j] = '-';
			tiles[i][j] = '0';
		}
	}

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");

		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl; //top border visual fix
		for (int i = 0; i < mapHeight; i++)
		{
			cout << "|"; //left border visual fix
			for (int j = 0; j < mapWidth; j++)
			{
				cout << tiles[i][j] << sideBorder[i][j];
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

