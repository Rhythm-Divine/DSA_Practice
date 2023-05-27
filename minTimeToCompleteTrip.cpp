#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &time, long long mid)
{
    long long int sum = 0;
    for (auto i : time)
    {
        sum += mid / i;
    }
    return sum;
}
long long minimumTime(vector<int> &time, int totalTrips)
{
    sort(time.begin(), time.end());
    long long s = 1;
    long long e = time[0];
    e=e*totalTrips;

    while (s < e)
    {
        long long mid = s + (e - s) / 2;
        if (solve(time, mid) >= totalTrips)
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

    int main(){
        vector<int> time={10000};
        cout<<minimumTime(time,10000000)<<endl;
    }