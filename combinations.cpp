#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i,int n,int k){
        if(i>n){
            return;
        }
        if(k==0){
            ans.push_back(temp);
            temp.clear();
            return;
        }
        temp.push_back(i);
        solve(i+1,n,k-1);
        temp.pop_back();
        solve(i+1,n,k);

    }
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return ans;
    }

    int main(){
        vector<vector<int>> v=combine(4,2);
        for(auto i:v){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }