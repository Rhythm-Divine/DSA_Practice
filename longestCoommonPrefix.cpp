#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    
    sort(strs.begin(), strs.end());
    int n = strs.size();
   
    int y = min(strs[0].length(), strs[n - 1].length());
    for (int i = 0; i < y; i++)
    {
        if (strs[0][i] != strs[n - 1][i])
        {
            break;
        }else{
            ans+=strs[0][i];
        }
    }
    return ans;
}

int main()
{
    vector<string> str = {"flower", "flow", "flowht"};
    string ans = longestCommonPrefix(str);

    cout << ans << endl;
}