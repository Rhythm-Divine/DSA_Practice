#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &v)
{
    set<int> st;
    for(auto i:v){
        st.insert(i);
    }

}
bool equalFrequency(string word)
{
    if (word.length() == 2)
    {
        return true;
    }
    vector<int> v(26, 0);
    for (auto c : word)
    {
        v[c - 'a']++;
    }
    for (auto c : word)
    {
        v[c - 'a']--;
        if (check(v))
        {
            return true;
        }
        v[c - 'a']++;
    }
    return false;
}

int main()
{
    string s = "cbbd";
    cout << equalFrequency(s);
}