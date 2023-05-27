#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int h[26]={0};
    cin>>n;
    char s1[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>s1[i];
    }
    char s2[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>s2[i];
    }
    for(int i=0;i<n;i++){
        h[s1[i]-97]++;
    }
    for(int i=0;i<n;i++){
        h[s2[i]-97]--;
        if(h[s1[i]-97]<0){
            cout<<"Not anagram"<<endl;
            break;
        }
            if(s2[i]=='\0'){
                cout<<"Anagram"<<endl;
            }
}
}