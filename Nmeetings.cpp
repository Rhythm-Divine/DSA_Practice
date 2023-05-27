#include <bits/stdc++.h>
using namespace std;
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());

    int x = v[0].first;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second > x)
        {
            count++;
            x = v[i].first;
        }
        else
        {
            continue;
        }
    }
    return count;
}
int main()
{
    int start[6] = {900, 940, 950, 1100, 1500, 1800};
    int end[6] = {910, 1200, 1120, 1130, 1900, 2000};

    cout << maxMeetings(start, end, 6) << endl;
}