 #include<bits/stdc++.h>
 using namespace std;

 vector<int> temp;
    void kadane(vector<int> &nums,int j){
        int n=nums.size();
        int currSum=nums[j];
        int ovrSum=nums[j];


        for(int i=j+1;i<nums.size()+j;i++){
            currSum=max(nums[i%n],currSum+nums[i%n]);
            ovrSum=max(ovrSum,currSum);
        }
        temp.push_back(ovrSum);
        return;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        for(int j=0;j<n;j++){
            kadane(nums,j);
        }
        int ans=*max_element(temp.begin(),temp.end());
        return ans;
    }

int main(){
    vector<int> x={5,-3,5};
    cout<<maxSubarraySumCircular(x)<<endl;
}