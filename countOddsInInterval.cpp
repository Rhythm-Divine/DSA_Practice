#include <bits/stdc++.h>
using namespace std;

int countOdds(int low, int high)
{
    int ans;
    double n = high - low + 1;
    if (low % 2 == 0 && high % 2 == 0)
    {
        ans = floor(n / 2);
    }
    else if (low % 2 != 0 && high % 2 != 0)
    {
        cout<<n/2<<endl;
        ans = ceil(n / 2);
    }
    else
    {
       
    }
    return ans;
}
int main()
{
    cout<<countOdds(3,7)<<endl;
}