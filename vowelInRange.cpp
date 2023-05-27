#include <bits/stdc++.h>
using namespace std;

bool check(string w)
{

    if ((w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'o' || w[0] == 'u') && (w[w.length() - 1] == 'a' || w[w.length() - 1] == 'e' || w[w.length() - 1] == 'i' || w[w.length() - 1] == 'o' || w[w.length() - 1] == 'u'))
    {
        return true;
    }
    return false;
}
int vowelStrings(vector<string> &words, int left, int right)
{
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        cout << check(words[i]) << endl;
        if (check(words[i]))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    vector<string> v={"are","amy","u"};
    cout<<vowelStrings(v,0,2)<<endl;
}