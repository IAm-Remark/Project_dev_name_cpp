#pragma once

#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


vector<vector<string>> ChangeCellNum(vector<vector<string>> field, int x, int y)
{
    if (x > 9 or y > 9 or x < 0 or y < 0) {
        cout << x << "\n";
        cout << y << "\n";
    }
    if (field[x][y] != "X") {
        int currentNum = stoi(field[x][y]);
        field[x][y] = to_string(currentNum + 1);
    }
    return field;
}


vector<vector<string>> ToGen(const int x, const int m) 
{
    srand(time(0));
    int mineOnLine = m / x;
    int currentMine = 0;

	vector<vector<string>> NewField(x, vector<string>(x, "0"));


    for (int i = 0; i < x; i++)
    {

        bool isHaveMine = false;
        for (int j = 0; j < x; j++)
        {
            int c = rand() % (1 - 0 + 1);
            if (c == 1 and currentMine < m and not isHaveMine)
            {
                NewField[i][j] = "X";
                currentMine++;
                if (currentMine % 2 == 0) isHaveMine = true;
            }
        }
    }


    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (NewField[i][j] == "X")
            {
                if (i != 0) {
                    NewField = ChangeCellNum(NewField, i - 1, j);
                    if (j != x - 1) NewField = ChangeCellNum(NewField, i - 1, j + 1);
                    if (j != 0) {
                        NewField = ChangeCellNum(NewField, i - 1, j - 1);
                    }
                }
                if (i != x - 1) {
                    NewField = ChangeCellNum(NewField, i + 1, j);
                    if (j != x - 1) {
                        if (j != 0) NewField = ChangeCellNum(NewField, i + 1, j - 1);
                        NewField = ChangeCellNum(NewField, i + 1, j + 1);
                    }
                }
                if (j != 0) NewField = ChangeCellNum(NewField, i, j - 1);
                if (j != x - 1) NewField = ChangeCellNum(NewField, i, j + 1);
            }
        }
    }


    //cout << currentMine;
	return NewField;
}