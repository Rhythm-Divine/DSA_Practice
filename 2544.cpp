#include <bits/stdc++.h>
using namespace std;

int alternateDigitSum(int n)
{
    string s = to_string(n);
    long long int ans = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (flag)
        {
            ans += (s[i] - '0');
            flag=!flag;
        }
        else
        {
            ans -= (s[i] - '0');
        }
    }
    return ans;
}
int main()
{
    cout<<alternateDigitSum(521);
}