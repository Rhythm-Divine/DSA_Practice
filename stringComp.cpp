#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
        int n=chars.size();
        if(n==1){
            return 1;
        }
        int count=1;
        int x=1;
        string s="";
        for(int i=0;i<n-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }else{
                if(count>=10){
                    s=to_string(count);
                    for(auto c:s){
                        chars[x]=c;
                    }               
                }
                else{
                    chars[x]=char(count+'0');
                }
                x+=2;
                count=1;
                i++;
            }
        
        }
        return x;
    }

    int main()
    {
        vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'
        };
        int ans = compress(chars);
        for (int i = 0; i < ans; i++)
        {
            cout << chars[i] << " ";
        }
    }