#include <bits/stdc++.h>
using namespace std;

int minMutation(string start, string end, vector<string> &bank)
{

    unordered_set<string> s(bank.begin(), bank.end());

    if (s.count(end) == 0)
    {
        return -1;
    }

    queue<string> q;

    q.push(start);

    int count = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            string curr = q.front();

            q.pop();

            if (curr == end)
                return count;

            s.erase(curr);

            for (int i = 0; i < 8; i++)
            {
                string modified = curr;

                modified[i] = 'A';

                if (s.count(modified))
                    q.push(modified);

                modified[i] = 'C';

                if (s.count(modified))
                    q.push(modified);

                modified[i] = 'G';

                if (s.count(modified))
                    q.push(modified);

                modified[i] = 'T';

                if (s.count(modified))
                    q.push(modified);
            }
        }

        count++;
    }

    return -1;
}

int main()
{

    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    int ans = minMutation(start, end, bank);
    cout << ans;
}