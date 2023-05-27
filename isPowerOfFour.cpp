#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long int lli;

bool isPowerOfFour(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    else
    {
        if (n % 4 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    lli n = -2147483648;
    bool flag = isPowerOfFour(n);
    cout << flag << endl;
}