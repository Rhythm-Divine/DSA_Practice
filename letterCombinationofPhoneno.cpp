#include <bits/stdc++.h>
using namespace std;

void DFS(string digits, string &x, int idx, vector<string> &ans, vector<string> &v)
{
    if (idx >= digits.length())
    {
        ans.push_back(x);
        return;
    }
    string temp = v[digits[idx] - '0'];
    for (int i = 0; i < temp.size(); i++)
    {
        x.push_back(temp[i]);
        DFS(digits, x, idx + 1, ans, v);
        x.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    int n = digits.length();
    int idx = 0;
    vector<string> ans;
    string x = "";
    vector<string> v =
        {"", "", "abc",
         "def",
         "ghi",
         "jkl",
         "mno",
         "pqrs",
         "tuv",
         "wxyz"};

    if (n == 0)
    {
        return {};
    }
    DFS(digits, x, idx, ans, v);

    return ans;
}

int main()
{
    string s = "23";
    vector<string> ans = letterCombinations(s);
    for (auto i : ans)
    {
        cout << i << ",";
    }
}