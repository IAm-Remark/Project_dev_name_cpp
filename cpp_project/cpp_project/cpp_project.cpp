#include <iostream>

using namespace std;

const int SizeXI = 15;
const int SizeYI = 15;
int MatrixI[SizeXI][SizeYI];

void FieldMatrixC(int Matrix[SizeXI][SizeYI])
{
    for (int i = 0; i <= SizeXI; i++)
    {
        for (int j = 0; j <= SizeYI; j++)
        {
            Matrix[i][j] = j;
            //cout << Matrix[i][j];
        }
        //cout << "\n";
    }
}


int main()
{
    
    FieldMatrixC(MatrixI);
    
    

}

