#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int n = s.length();
    int i = 0;
    int j = 0;

    while (j <= n && i <= j)
    {
        if (isspace(s[j]) || j==n)
        {
            reverse(s.begin()+i, s.begin() + j);
            
            j++;
            i=j;

        }
       
        else
        {
            j++;
        }
    }
    return s;
}
int main()
{
    string s = "Let's take LeetCode contest";
    string ans = reverseWords(s);
    cout << ans << endl;
}