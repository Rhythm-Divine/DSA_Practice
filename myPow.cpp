#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1;
    if (n == 0)
    {
        return ans;
    }
    if (n < 0)
    {
        n=-1*n;
        for (long long int i = 0; i < n; i++)
        {
            ans *= x;
        }
        ans = (double)1 / ans;
        return ans;
    }
    for (long long int i = 0; i < n; i++)
    {
        ans *= x;
    }
    return ans;
}

int main()
{
    double ans=myPow(-2,3);
    cout<<ans<<endl;
}