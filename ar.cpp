#include<bits/stdc++.h>
using namespace std;


int maxEvents(vector<vector<int>>& events) {
    int n = events.size();

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int> > pq;

    int ans = 0, i = 0, day = 0;
    while (!pq.empty() || i < n) {
        if (pq.empty()) day = events[i][0];

        while (i < n && events[i][0] == day) pq.push(events[i++][1]);

        ++ans; pq.pop();
        ++day;

        while (!pq.empty() && pq.top() < day) pq.pop();
    }

    return ans;
}
int main(){
    vector<vector<int>> vec={{1,2},{2,3},{3,4},{1,2}};
    cout<<maxEvents(vec)<<endl;
}