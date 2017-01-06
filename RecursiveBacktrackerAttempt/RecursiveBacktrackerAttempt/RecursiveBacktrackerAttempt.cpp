#include "stdafx.h"
#include <iostream>
#include <chrono>  //for pausing
#include <thread>  //for pausing
#include <cstdlib> //random values
#include <vector>  //backtracking

using namespace std;

const int mapWidth = 59, mapHeight = 14;
char playerChar = '@', discoveredChar = '.', undiscoveredChar = '#';

void draw(int x, int y, char sideBorder[mapHeight][mapWidth], char bottomBorder[mapHeight][mapWidth], char tiles[mapHeight][mapWidth]);
vector<char> getNeighbors(int x, int y, char tiles[mapHeight][mapWidth]);

int main()
{
	srand(time(NULL)); //init random seed
	bool finished = false, drawgeneration = false;

	char sideBorder[mapHeight][mapWidth], bottomBorder[mapHeight][mapWidth], tiles[mapHeight][mapWidth];
	int x = floor(mapWidth/2), y = floor(mapHeight/2), waitTime = 0;
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

	char answer;
	cout << "Draw during generation? (y/n): ";
	cin >> answer;
	cin.ignore();
	switch (answer)
	{
	case('y'):
	case('Y'):
		drawgeneration = true;
		break;
	case('n'):
	case('N'):
	default:
		drawgeneration = false;
		break;
	}
	if (drawgeneration)
	{
		cout << "Millisecond wait-time between frames? (0-1000): ";
		cin >> waitTime;
		if (waitTime > 1000) waitTime = 1000;
		if (waitTime < 0) waitTime = 0;
		cin.ignore();
	}

	while (!finished)
	{
		if (waitTime > 0) std::this_thread::sleep_for(std::chrono::milliseconds(waitTime)); //pause to account for CMD visual stutter

		tiles[y][x] = discoveredChar;

		vector<char> dirs = getNeighbors(x, y, tiles);
		switch (dirs[rand() % (dirs.size())])
		{
		case 'r':
			x++;
			sideBorder[y][x-1] = ' ';
			xhistory.push_back(x);
			yhistory.push_back(y);
			break;
		case 'd':
			y++;
			bottomBorder[y-1][x] = ' ';
			xhistory.push_back(x);
			yhistory.push_back(y);
			break;
		case 'l':
			x--;
			sideBorder[y][x] = ' ';
			xhistory.push_back(x);
			yhistory.push_back(y);
			break;
		case 'u':
			y--;
			bottomBorder[y][x] = ' ';
			xhistory.push_back(x);
			yhistory.push_back(y);
			break;
		case 'n': //no neighbors
			if (xhistory.size() > 0)
			{
				x = xhistory.back();
				y = yhistory.back();
				xhistory.pop_back();
				yhistory.pop_back();
			}
			else finished = 1;
			break;
		}

		if (drawgeneration) draw(x, y, sideBorder, bottomBorder, tiles);
	}
	
	draw(x, y, sideBorder, bottomBorder, tiles);
	std::system("pause");
	return 0;
}

void draw(int x, int y, char sideBorder[mapHeight][mapWidth], char bottomBorder[mapHeight][mapWidth], char tiles[mapHeight][mapWidth]) {

	std::system("cls");

	for (int i = 0; i < mapWidth; i++) //Top border visual fix
	{
		cout << "+-";
	}
	cout << "+" << endl;

	for (int i = 0; i < mapHeight; i++) //display board
	{
		cout << "|"; //left border visual fix
		for (int j = 0; j < mapWidth; j++)
		{
			if (x == j && i == y) cout << playerChar; //display current tile
			else cout << tiles[i][j]; //else display tile state

			cout << sideBorder[i][j];
		}
		cout << endl << "+"; //left border visual fix

		for (int j = 0; j < mapWidth; j++)
		{
			cout << bottomBorder[i][j] << "+";
		}
		cout << endl;
	}
}

vector<char> getNeighbors(int x, int y, char tiles[mapHeight][mapWidth]) {
	vector<char> neighbors;
	
	if (x < mapWidth - 1) if (tiles[y][x + 1] == undiscoveredChar) neighbors.push_back('r');
	if (y < mapHeight - 1) if (tiles[y + 1][x] == undiscoveredChar) neighbors.push_back('d');
	if (x > 0) if (tiles[y][x - 1] == undiscoveredChar) neighbors.push_back('l');
	if (y > 0) if (tiles[y - 1][x] == undiscoveredChar) neighbors.push_back('u');
	
	if (neighbors.size() == 0) neighbors.push_back('n');

	return neighbors;
}