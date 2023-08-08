#include<bits/stdc++.h>
using namespace std;

bool solve(string s){
    int n=s.length();
    if(n==1 && s[0]=='1'){
        return true;
    }

    string str="";

    for(int i=0;i<n;i++){
        if(str.size()==0){
            str+=s[i];
            continue;
        }
        if(s[i]==str[0]){
            str+=s[i];
        }else{
            str.clear();
        }
        if(str.size()>1 && str.size()+'0'==s[i]){
            return true;
        }
    }
    return false;
}
int main(){
    string s="6539923335";
    cout<<boolalpha<<solve(s)<<endl;
}