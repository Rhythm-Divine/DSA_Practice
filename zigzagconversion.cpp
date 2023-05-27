#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{

    string arr[numRows];
    int index = 0;
    bool flag = true;

    if (numRows == 1)
    {
        return s;
    }

    for (int i = 0; i < s.length(); i++)
    {
        arr[index].push_back(s[i]);
        if (index == numRows - 1)
        {
            flag = false;
        }
        else if (index == 0)
        {
            flag = true;
        }
        if (flag)
        {
            index++;
        }
        else
        {
            index--;
        }
    }
    string ans = "";

    for (int i = 0; i < numRows; i++)
    {
        ans += arr[i];
    }
    return ans;
}
int main()
{
    string s = "paypalishiring";
    string x = convert(s, 1);
    cout << x << endl;
}