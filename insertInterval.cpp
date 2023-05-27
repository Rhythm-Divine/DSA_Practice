#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int count = 0;
    for (auto i : intervals)
    {

        if (i[1] >= newInterval[0])
        {
            break;
        }
        count++;
        ans.push_back(i);
    }
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    vector<int> temp = newInterval;
    temp[0] = min(intervals[count][0], newInterval[0]);
    while (count < intervals.size() && intervals[count][0] <= newInterval[1])
    {
        
        temp[1] = max(intervals[count++][1], newInterval[1]);
    }
    ans.push_back(temp);

    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    while (count < intervals.size())
    {
        ans.push_back(intervals[count++]);
    }
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return ans;
}
int main()
{
    vector<vector<int>> x = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> in = {4, 8};
    vector<vector<int>> ans = insert(x, in);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}