#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string temp;

void solve(int idx, string s)
{
    if (idx >= s.length())
    {
        ans.push_back(temp);
        return;
    }
    solve(idx + 1, s);
    temp.push_back(s[idx]);
    solve(idx + 1, s);
    temp.pop_back();
}
int main()
{
    string s = "abc";
    solve(0, s);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << endl;
    }
}