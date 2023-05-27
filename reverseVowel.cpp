#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    return false;
}
string reverseVowels(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            stk.push(s[i]);
            s[i] = '0';
        }
        else
        {
            continue;
        }
    }
    char temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            temp = stk.top();

            stk.pop();
            s[i] = temp;
        }
        else
        {
            continue;
        }
    }
    return s;
}
int main()
{
    string s = "";
    string ans = reverseVowels(s);
    cout << ans << endl;
}

