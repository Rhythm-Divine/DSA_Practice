#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="I am a Good boy";
    stringstream ss(s);
    string t;

    getline(ss,t,' ');
    cout<<t<<endl;
    getline(ss,t,' ');
    cout<<t<<endl;
    getline(ss,t,' ');
    cout<<t<<endl;
}