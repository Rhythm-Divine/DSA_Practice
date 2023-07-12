#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;
    queue<int> q;
    int l = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
        if (i - l + 1 == K)
        {
            if (q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
            }
            if (A[l] < 0)
            {
                q.pop();
            }
            l++;
        }
    }
    return ans;
}

int main()
{
    long long v[8] = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<long long> x = printFirstNegativeInteger(v, 8, 3);
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout<<endl;
    unordered_map<int,int> m;
    for(int i=0;i<4;i++){
        m[i]=0;
    }
    cout<<m.size()<<endl;
}