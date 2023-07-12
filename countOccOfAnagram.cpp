#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    int k = pat.length();
    int n = txt.length();
    int l = 0;
    int ans = 0;
    vector<int> m(26,0);
    vector<int> m1(26,0);
    for (auto c : pat)
    {
        m[c-'a']++;
    }
    for (int i = 0; i < n; i++)
    {

        m1[txt[i]-'a']++;
        if (i - l + 1 == k)
        {

            if (m == m1)
            {
                ans++;
            }

            m1[txt[l]-'a']--;
            l++;
        }
    }
    return ans;
}

int main()
{
    string s = "forxxorfxdofr";
    cout << search("for", s) << endl;
}