#include <iostream>
#include <windows.h>
#include <string>
#include "fieldgen.h"
using namespace std;

HANDLE Handler = GetStdHandle(STD_OUTPUT_HANDLE);
vector<int> Color = {7, 15, 9, 12, 13, 11, 14, 10, 15};
vector<string> Alphabet = { "A", "B", "C", "D", "E",
                            "F", "G", "H", "I", "J", "K",
                            "L", "M", "N", "O", "P", "Q",
                            "R", "S", "T", "U", "V", "W",
                            "X", "Y", "Z" };

const int fieldsize = 10;
const int mineCount = 25;


void PrintField(vector<vector<string>> FieldBlank, vector<vector<string>> Field)
{
    for (int i = 0; i < fieldsize + 1; i++)
    {
        for (int j = 0; j < fieldsize + 1; j++)
        {
            if (i != 0 and j != 0) {
                if (Field[i - 1][j - 1] == "0")
                {
                    FieldBlank[i][j] = Field[i - 1][j - 1];
                }
                if (FieldBlank[i][j] != "N") SetConsoleTextAttribute(Handler, Color[stoi(FieldBlank[i][j])]);
                if (FieldBlank[i][j] == "N") SetConsoleTextAttribute(Handler, 2);
            }
            cout << FieldBlank[i][j];
            SetConsoleTextAttribute(Handler, Color[0]);
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < fieldsize; i++)
    {
        for (int j = 0; j < fieldsize; j++)
        {
            cout << Field[i][j];
        }
        cout << "\n";
    }
}


int AlphabetParser(string toparse) 
{
    for (int i = 0; size(Alphabet); i++) 
    {
        if (toparse == Alphabet[i]) return i;
    }
}


int main()
{
    vector<vector<string>> Field = ToGen(fieldsize, mineCount);
    vector<vector<string>> FieldBlank = ToGenBlank(fieldsize);

    PrintField(FieldBlank, Field);
    for (int i = 0; i < mineCount;)
    {
        int row;
        int colInt;
        string col;

        cout << "\n" << "Enter line: ";
        cin >> row;
        cout << "\n" << "Enter col: ";
        cin >> col;

        colInt = AlphabetParser(col);
        FieldBlank[row + 1][colInt + 1] = Field[row][colInt];
        if (Field[row][colInt] == "X") i++;

        system("cls");
        PrintField(FieldBlank, Field);
    }
}
