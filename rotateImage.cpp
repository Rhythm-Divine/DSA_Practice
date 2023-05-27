#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    vector<int> temp;
    int n = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            swap(matrix[i][j], matrix[j][i]);
            // matrix[i][j]=matrix[n-j-1][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> x = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto i : x)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
    }
    cout << endl;
    rotate(x);
    for (auto i : x)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
    }
}