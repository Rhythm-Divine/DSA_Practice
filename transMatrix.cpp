#include <bits./stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    vector<int> x(matrix[0].size(), 0);
    vector<vector<int>> ans(matrix.size(), x);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans[j][i] = matrix[i][j];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> x = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> y = transpose(x);
    for (auto i : y)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}