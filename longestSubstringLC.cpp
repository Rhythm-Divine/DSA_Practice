#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_set<char> m;
    int i=0;
    int j=0;
    int maximum=0;

    while(j<s.length()){
        if(!m.count(s[j])){
            m.emplace(s[j]);
            j++;
            int x=m.size();
            maximum=max(x,maximum);
        }else{
            m.erase(s[i]);
            i++;
        }
    }
    cout<<maximum<<endl;
}