#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int ans=0;
    int n=height.size();
    int end=height[n];
    int i=0;
   
        while(i<n){
         ans=max((n-i-1)*min(height[i],height[n-1]),ans);
         if(height[i]>height[n-1]){
            n--;
         }else{
            i++;
         }
        }
        return ans;
    }
int main(){
    vector<int> x={2,3,4,5,18,17,6};
    int ans=maxArea(x);
    cout<<ans<<endl;
}