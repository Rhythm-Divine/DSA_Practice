#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m,int n){
    int x=m+n-2; //Total steps
    int y=n-1;  //n-1 down or right steps out of m-n-2 total steps
    int ans =1;
    for(int i=1;i<=y;i++){
        ans=ans * ((x-y) +i)/i;
    }
    return ans;
}
int main(){
     int x= uniquePaths(3,7);
    cout<<x<<endl;
}