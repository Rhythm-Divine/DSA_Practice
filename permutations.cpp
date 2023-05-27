#include<bits/stdc++.h>
using namespace std;

  vector<vector<int>> ans;
    void solve(int idx,vector<int>& nums){
       if(idx==nums.size()){
           ans.push_back(nums);
           return;
       }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums);
        return ans;
    } 

int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=permute(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}