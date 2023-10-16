#pragma once

#include <ctime>
#include <vector>
#include <iostream>
using namespace std;


vector<vector<string>> ToGen(const int x, const int m) 
{
    srand(time(0));
    int mineOnLine = m / x;
    int currentMine = 0;

	vector<vector<string>> NewField(x, vector<string>(x, "O "));


    for (int i = 0; i < x; i++)
    {
        bool isHaveMine = false;
        for (int j = 0; j < x; j++)
        {
            int c = rand() % (1 - 0 + 1);
            if (c == 1 and currentMine < m and not isHaveMine)
            {
                NewField[i][j] = "X ";
                currentMine++;
                if (currentMine % 2 == 0) isHaveMine = true;
            }
        }
    }
    

    int charInd = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (NewField[i][j] != "X ")
            {
                 
            }
        }
    }

    //cout << currentMine;
	return NewField;
}

