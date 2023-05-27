#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    int temp;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
        {
            temp = i;
            break;
            
        }
        else
        {
            temp = -1;
        }
    }
    return temp;
}

int main()
{
    string s;
    s = "aabb";
    int ans;
    ans = firstUniqChar(s);
    cout << ans << endl;
}