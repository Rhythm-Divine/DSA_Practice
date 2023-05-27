#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(target-nums[i])){
            return {m[target-nums[i]],i};
            }
            m[nums[i]]=i;
        }
        return {-1,-1};
     };
int main(){
     
     vector<int> x;
    vector<int> vec={2,4,6,4};
     x=twoSum(vec,8);
     for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
     }
}