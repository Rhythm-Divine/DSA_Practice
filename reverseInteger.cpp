#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    string s;
    bool flag = false;
    s = to_string(x);
    if (s[0] == '-')
    {
        s = s.substr(1);
        flag = true;
    }

    std::reverse(s.begin(), s.end());
    if (flag)
    {
        s = '-' + s;
    }
    long long int ans;
    ans = stoll(s);
    if (ans > INT32_MAX || ans < INT32_MIN)
    {
        ans = 0;
    }

    return ans;
}
int main()
{
    int a = -1536469;
    int x = reverse(a);
    cout << x << endl;
}