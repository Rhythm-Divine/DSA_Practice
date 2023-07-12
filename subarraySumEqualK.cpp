#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &arr , int N){
        int l=0;
        int sum=0;
        int ans=INT_MIN;
        int i=0;
        while(i<N){
            sum+=arr[i];
            if(i-l+1==K){
                ans=max(ans,sum);
                sum-=arr[l];
                l++;
            }
            
            i++;
        }
        return ans;
    }

int main()
{
    vector<int> v={100,200,300,400};
    cout<<maximumSumSubarray(2,v,4);
}