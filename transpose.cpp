#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<int>> matrix);

int main()
{
    vector<vector<int>> matrix;
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    transpose(matrix);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void transpose(vector<vector<int>> matrix){
    int temp;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}