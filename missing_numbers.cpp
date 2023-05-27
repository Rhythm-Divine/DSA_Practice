#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int diff=a[0];
    int m=0;
    for (size_t i = 0; i < n; i++)
    {
        if(diff!=a[i]-i){
            while(diff<a[i]-i){
                m=diff + i;
                cout<<m<<endl;
                diff++;
            }
        }
    }
    

}