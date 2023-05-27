#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    if (s.length() < 1 || s[0] == '0')
    {
        return 0;
    }
    if(s.length()==1){
        return 1;
    }

    int v1 = 1;
    int v2 = 1;
    int value = 0;
    int d1;
    int d2;
    for (int i = 1; i < s.length(); i++)
    {
        d1 = s[i] - '0';
        d2 = (s[i - 1] -'0') * 10 + d1;
        value=0;
        if (d1 >= 1)
        {
            value += v2;
        }
        if (d2 >= 10 && d2 <= 26)
        {
            value += v1;
        }
        v1 = v2;
        v2 = value;
    }
    return v2;
}

int main()
{
    string s = "12324";
    int ans = numDecodings(s);
    cout << ans << endl;
}