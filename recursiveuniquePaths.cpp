#include <bits/stdc++.h>
using namespace std;

int countPaths(int i,int j,int m,int n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i>=m || j>=n){
        return 0;
    }
    else{
        
        int y=countPaths(i+1,j,m,n)+ countPaths(i,j+1,m,n);
        cout<<y<<endl;
        return y;
    }
}
int recursiveuniquePaths(int m,int n){
    int ans= countPaths(0,0,m,n);
    return ans;
}
int main(){
    int x= recursiveuniquePaths(3,2);
    cout<<x<<endl;
}