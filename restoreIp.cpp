#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
bool isValid(string s)
{
    if (s.length() > 3 || s.length() == 0 || (s[0] == '0' && s.length() > 1) || stoi(s) > 255)
    {
        return false;
    }
    return true;
}

vector<string> restoreIpAddresses(string s)
{
    if (s.length() > 12)
    {
        return {};
    }

    for (int i = 1; i < 4 && i < s.length(); i++)
    {
        for (int j = i + 1; j < i + 4 && j < s.length(); j++)
        {
            for (int k = j + 1; k < j + 4 && k < s.length(); k++)
            {
                string str1 = s.substr(0, i), str2 = s.substr(i, j - i), str3 = s.substr(j, k - j), str4 = s.substr(k);
                cout<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" ";
                cout<<endl;
                if (isValid(str1) && isValid(str2) && isValid(str3) && isValid(str4))
                {
                    ans.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s = "25525511135";
    vector<string> ans = restoreIpAddresses(s);
    for (auto str : ans)
    {
        cout << str << endl;
    }
}
