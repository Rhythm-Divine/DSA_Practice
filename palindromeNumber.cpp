#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{

    vector<long long int> vec;
    vector<long long int> v;
    bool flag = false;
    string s = to_string(x);
    if (s[0] == '-')
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        int digit = x % 10;
        vec.push_back(digit);
        v.emplace_back(digit);
        x = x / 10;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == v[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    int x = 1000021;
    bool ans = isPalindrome(x);
    cout << ans << endl;
}