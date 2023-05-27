#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;
bool isPalindrome(string s)
{
    int beg = 0;
    int end = s.length() - 1;
    while (beg <= end)
    {
        if (s[beg] != s[end])
        {
            return false;
        }
        beg++;
        end--;
    }
    return true;
}
void solve(string s, vector<string> &x)
{
    if (s.length() == 0)
    {
        ans.push_back(x);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string temp = s.substr(0, i + 1);
        string pas = s.substr(i + 1);
        if (isPalindrome(temp))
        {

            x.push_back(temp);
            solve(pas, x);
            x.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> x;
    solve(s,x);
    return ans;
}

int main()
{
    string a = "aabb";
    vector<vector<string>> ans = partition(a);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}