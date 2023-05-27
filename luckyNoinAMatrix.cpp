#include <bits/stdc++.h>
using namespace std;

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        m[*min_element(matrix[i].begin(), matrix[i].end())]++;
    }

    for (int i = 0; i < matrix[i].size(); i++)
    {
        int maxC = INT_MIN;
        for (int j = 0; j < matrix.size(); j++)
        {
            maxC = max(maxC, matrix[j][i]);
        }
        m[maxC]++;
    }
    for (auto it : m)
    {
        if (it.second > 1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> temp = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> x = luckyNumbers(temp);
    for (auto i : x)
    {
        cout << i << " ";
    }
}