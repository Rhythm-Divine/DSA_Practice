#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int tSum=0;
        int i=0;
        if(n==1){
            return sum;
        }
        int maxm=INT16_MIN;
        for(int j=i+1;j<n;j++){
            tSum=sum+nums[j];
            if(tSum>=sum){
                j++;
            }else{
                i++;
            }
        }
        return tSum;
    }
int main(){
    vector<int> x={-2,1,-3,4,-1,2,1,-5,4};
    int ans=maxSubArray(x);
    cout<<ans;
}