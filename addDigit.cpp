#include <bits/stdc++.h>
using namespace std;

int addDigits(int num)
{
    long long int ans = num;
    string s = to_string(num);
    while (s.size() != 1)
    {
        ans=0;
        for (auto c : s)
        {
            ans += c - '0';
        }
        s = to_string(ans);
    }
    return ans;
}
int main()
{
    cout<<addDigits(100);
}