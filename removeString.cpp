#include <bits/stdc++.h>
using namespace std;

string removeStars(string s)
{
    int x = 0;
    for (auto i : s)
    {
        if (i == '*')
        {
            x--;
        }
        else
        {
            s[x] = i;
            x++;
        }
    }
    while (x < s.size())
    {
        s.pop_back();
    }
    return s;
}
int main()
{
    string s="leet**cod*e";
    string ans=removeStars(s);

    for(auto c:ans){
        cout<<c;
    }
}