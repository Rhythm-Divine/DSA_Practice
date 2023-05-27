#include<bits/stdc++.h>
using namespace std;

    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]!=arr[i+1]-1){
                k--;
            }
            if(k==0){
                return i+1;
            }
        }
        return n+k;
    }

int main(){
    vector<int> x={2,3,4,7,11};
    cout<<findKthPositive(x,5)<<endl;
}
