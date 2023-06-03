#include <bits/stdc++.h>
using namespace std;

bool digitCount(string num)
{
    int n = num.size();
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++)
    {
        
        cnt[num[i]-'0']++;
    }

    for (int i = 0; i < n; i++)
    {
        if (cnt[i] != num[i]-'0')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s = "1210";
    cout << boolalpha << digitCount(s) << endl;
}