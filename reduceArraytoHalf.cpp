#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    unordered_map<int, int>::iterator itr;
    itr = m.begin();

    // for (itr; itr != m.end(); itr++)
    // {
    //     cout << itr->first << "->" << itr->second << endl;
    // }
    vector<int> freq;

    for (itr; itr != m.end(); itr++)
    {
        freq.push_back(itr->second);
    }
    sort(freq.begin(), freq.end(), greater<>());
    for (int i = 0; i < freq.size(); i++)
    {
        sum += freq[i];
        if (sum >= n / 2)
        {
            ans = i + 1;
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int> x = {7,7,7,7,7,7};
    int ans = minSetSize(x);
    cout<<ans<<endl;
}