#include <bits/stdc++.h>
using namespace std;
string makeGood(string s)
{

    for (int i = 0; i < s.length() - 1; i++)
    {
        if ((s[i] == s[i + 1] + 32) || (s[i] == s[i + 1] - 32))
        {
            s.erase(i, 2);
            // i = max(-1, i - 2);
            i = i - 2;
            if (i < -1)
            {
                i = -1;
            }
        }
        if (s.length() == 0)
            break;
    }
    return s;
}
int main()
{
    string s = "cC";
    string ans = makeGood(s);
    cout << ans << endl;
}