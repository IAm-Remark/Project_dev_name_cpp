#include <iostream>
#include "fieldgen.h"
using namespace std;


const int fieldsize = 10;
const int mineCount = 25;

int main()
{    
    
    vector<vector<string>> Field = ToGen(fieldsize, mineCount);
    for (int i = 0; i < fieldsize; i++)
    {
        for (int j = 0; j < fieldsize; j++)
        {
            cout << Field[i][j];
        }
        cout << "\n";
    }
}

