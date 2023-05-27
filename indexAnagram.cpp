#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p)
{
    if (p.length() > s.length())
    {
        return {};
    }
    bool zeros;
    vector<int> v(26, 0);
    vector<int> ans;
    for (int i = 0; i < p.length(); i++)
    {
        v[p[i] - 'a']++;
    }
    int idx = 0;
    for (int i = 0; i < s.length(); i++)
    {
        v[s[i] - 'a']--;
        int f = i - p.length();
        if (f >= 0)
        {
            v[s[f] - 'a']++;
            idx++;
        }
        zeros = std::all_of(v.begin(), v.end(), [](int i)
                            { return i == 0; });
        if (zeros)
        {
            ans.push_back(idx);
        }
    }
    return ans;
}
int main()
{

    string s = "cbaebabacd";
    string p = "abc";
    vector<int> a = findAnagrams(s, p);
    for (auto i : a)
    {
        cout << i << " " << endl;
    }
}