#include<bits/stdc++.h>
using namespace std;

  bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> hash;
        for(auto word:wordDict){
            hash.insert(word);
        }
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]==true && hash.find(s.substr(j,i))!=hash.end()){
                    dp[i]=true;
                    break;
                }
            
            }
        }
        for(auto it:dp){
            cout<<it<<" ";
        }
        cout<<endl;
        return dp[s.length()];
    }
int main(){
string s="applepenapple";
vector<string> dict={"apple","pen"};
bool flag = wordBreak(s,dict);
cout<<flag<<endl;

}