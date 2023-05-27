#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<string> x;
bool isPalindrome(string s)
{
    int beg = 0;
    int end = s.length() - 1;
    while (beg <= end)
    {
        if (s[beg] != s[end])
        {
            return false;
        }
        beg++;
        end--;
    }
    return true;
}
void solve(string s)
{
    if (s.length() == 0)
    {
        ans.push_back(x);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string temp = s.substr(0, i + 1);
        string pas = s.substr(i + 1);
        cout<<"temp : "<<temp<<" pas : "<<pas<<endl;
        if (isPalindrome(temp))
        {

            x.push_back(temp);
            solve(pas);
            x.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{

    solve(s);
    return ans;
}
int main()
{
    string s= "aab";
    vector<vector<string>> x=partition(s);
    cout<<"----------------------"<<endl;
    for(auto i:x){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}