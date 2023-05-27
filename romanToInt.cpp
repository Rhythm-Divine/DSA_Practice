#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{

    unordered_map<char, int> m = {{'M', 1000},
                                  {'D', 500},
                                  {'C', 100},
                                  {'L', 50},
                                  {'X', 10},
                                  {'V', 5},
                                  {'I', 1}};
    // m["M"] = 1000;
    // m["D"] = 500;
    // m["C"] = 100;
    // m["L"] = 50;
    // m["X"] = 10;
    // m["V"] = 5;
    // m["I"] = 1;

    int ans = m[s.back()];

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            ans-=m[s[i]];
        }
        else{
            ans+=m[s[i]];
        }
    }
    return ans;
}
int main()
{
    string a = "MMIV";
    int ans = romanToInt(a);
    cout << ans << endl;
}