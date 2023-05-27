#include<bits/stdc++.h>
using namespace std;
vector<int> v(26,0);
bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        bool zeros;
        for(int i=0;i<s1.length();i++){
            v[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            v[s2[i]-'a']--;
            int f=i-s1.length();
            if(f>=0){
                v[s2[i-s1.length()]-'a']++;
            }
         zeros = std::all_of(v.begin(), v.end(), [](int i) { return i==0; });
         if(zeros){
            return true;
         }
        }
        return false;
    }
int main(){
    string s1="ab";
    string s2="abc";
    cout<<checkInclusion(s1,s2)<<endl;
}