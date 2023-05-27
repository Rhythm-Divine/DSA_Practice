#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> findAllConcatenatedWords(vector<string> &words)
{
    unordered_set<string> s;
    vector<string> ans;

    for (string i : words)
    {
        s.insert(i);
    }

    for (string word : words)
    {
        if (word.empty())
            continue;
        int n = word.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!dp[i])
                continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (j - i < n && s.count(word.substr(i, j - i)))
                {
                    dp[j] = 1;
                }
            }
            if (dp[n])
            {
                ans.push_back(word);
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> ans = findAllConcatenatedWords(words);
    for (string word : ans)
    {
        cout << word << endl;
    }
    return 0;
}
