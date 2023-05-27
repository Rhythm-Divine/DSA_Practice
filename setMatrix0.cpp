#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    bool flag = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            flag = true;
        }
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (flag)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }

   
}

int main()
{
    vector<vector<int>> x = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(x);
     for (auto i : x)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}