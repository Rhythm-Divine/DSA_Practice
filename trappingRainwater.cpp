#include<bits/stdc++.h>
using namespace std;

 int trap(vector<int>& height) {
        stack<int> stk;
        int x=0;
        int ans=0;
        while(x<height.size()){
        while(!stk.empty() && height[x]>height[stk.top()]){
            int temp=stk.top();
            stk.pop();
            if(stk.empty()){
                break;
            }
            int dist = x-temp-1;
            ans=dist * (min(height[x],height[stk.top()])-height[temp]);
        }
            stk.push(x);
            x++;
     }
        return ans;
    }
int main(){
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap(v);
    cout<<ans<<endl;
}