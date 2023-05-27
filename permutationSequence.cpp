#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> temp;
void solve(int index, vector<int> &num)
{
    if (index == num.size())
    {
        return;
    }
    for (auto i : num)
    {
        cout << i << " ";
    }
    cout << endl;
    temp.push_back(num);
    for (int i = 1; i < num.size(); i++)
    {
        swap(num[index], num[index+i]);
        temp.push_back(num);
    }
    solve(index + 1, num);
}
string getPermutation(int n, int k)
{
    vector<int> num;

    for (int i = 1; i <= n; i++)
    {
        num.push_back(i);
    }
    solve(0, num);
    return "";
}
int main()
{
    string ans = getPermutation(3, 3);
}