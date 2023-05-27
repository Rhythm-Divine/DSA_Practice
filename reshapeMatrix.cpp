#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    if (mat.size() * mat[0].size() != r * c)
    {
        return mat;
    }
    vector<vector<int>> ans(r, vector<int>(c, 0));
    vector<int> tp;
    for(auto i:mat){
        for(auto j:i){
            tp.push_back(j);
        }
    }

    for (int i = r-1; i >= 0; i--)
    {
        for (int j = c-1; j >= 0; j--)
        {
            ans[i][j] =tp.back();
            tp.pop_back();
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> x = {{1, 2}, {3, 4}, {5,6}};
    vector<vector<int>> temp = matrixReshape(x, 2, 3);

    for (auto i : temp)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}