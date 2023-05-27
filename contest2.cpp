
#include <bits/stdc++.h>
using namespace std;

bool findMinSwap(vector<int> &A, int N)
{

    if (A.size() == 2)
    {
        if (A[0] > A[1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (is_sorted(A.begin(), A.end()))
    {
        return true;
    }
    vector<pair<int, int>> m(N);
    for (int i = 0; i < N; i++)
    {

        m[i].first = A[i];

        m[i].second = i;
    }

    sort(m.begin(), m.end());

    int swaps = 0;
    int x = 0;
    while (x < N)
    {
        if (m[x].second == x or m[x].first == A[x])
        {
            ++x;
            continue;
        }
        else
        {

            swap(m[x].first, m[m[x].second].first);

            swap(m[x].second, m[m[x].second].second);

            if (m[x].second != x)
                x--;
        }

        swaps++;

        ++x;
    }

    if (swaps == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> A = {1,2,3};

    int n = A.size();
    cout << is_sorted(A.begin(), A.end()) << endl;
    cout << findMinSwap(A, n) << '\n';
}