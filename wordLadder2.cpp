#include <bits/stdc++.h>
using namespace std;

bool hasAlmostSameStrings(vector<string> &words)
{
    unordered_set<string> data;
    for (auto &n : words)
    {
        for (int i = 0; i < static_cast<int>(n.size()); ++i)
        {
            string v = n.substr(0, i) + "*" + n.substr(i + 1);
            if (data.count(v))
                return true;
            data.insert(v);
        }
    }
    return false;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    vector<string> temp ;
    temp.push_back(beginWord);
    
    unordered_map<string, int> m;

    for (int i = 0; i < wordList.size() - 1; i++)
    {
        m[wordList[i]] = i;
    }
}

int main()
{
    vector<string> w={"dog","man","lcg"};
    bool flag;
    flag= hasAlmostSameStrings(w);
    cout<<flag<<endl;
}