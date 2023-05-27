#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{   
    if(s.length()!=t.length()){
        return false;
    }
    bool flag=false;
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<t.length();i++){
        arr[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            flag=false;
            break;
        }else
        {
            flag=true;
        }
    }
    return flag;
    }

int main()
{
    string s = "anagram";
    string t = "nagaram";

    bool flag = isAnagram(s, t);
    cout << flag <<boolalpha<< endl;
}