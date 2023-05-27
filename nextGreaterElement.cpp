#include <iostream>
#include <vector>
#include <string>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    vector<char> v(26,'0');
    for (auto c : letters)
    {
        int x = c - 'a';
        v[x]=c;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = (target - 'a') + 1; i < 26; i++)
    {
        if (v[i]!='0')
        {
            return v[i];
        }
    }
    return letters[0];
}

int main()
{
    vector<char> v = {'c', 'f', 'j'};
    cout << nextGreatestLetter(v, 'z');
}