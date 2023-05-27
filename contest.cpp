
#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}
vector<long long> solve(long long L, long long R) {
       vector<long long int>x;
       
    for (int i = L; i <= R; i++)
    {
        for (int j = L; j <= R; j++)
        {
            if (GCD(i, j) == 1)
            {
                x.push_back(i);
                x.push_back(j);
                return x;
            }
        }
    }
    if(x.size()==0){
        x.push_back(-1);
        x.push_back(-1);
    }
    return x;
    }
int main()
{
    vector<long long int>ans=solve(2,7);
    for(auto i:ans){
        cout<<i<<" ";
    }
}