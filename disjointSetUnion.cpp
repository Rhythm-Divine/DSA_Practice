#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> rank;
    vector<int> par;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        par.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int findPar(int u)
    {
        if (u == par[u])
        {
            return u;
        }
        return par[u] = findPar(par[u]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findPar(u);
        int up_v = findPar(v);

        if (rank[up_u] < rank[up_v])
        {
            par[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            par[up_v] = up_u;
        }
        else
        {
            par[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

int main()
{
    DSU dsu(7);
    for(auto i:dsu.rank){
        cout<<i<<" ";
    }
    cout<<endl;
    // Test Case 1
    cout << "Test Case 1:\n";
    dsu.unionByRank(1, 2);
    cout << "Parent of 1: " << dsu.findPar(1) << ", Rank of 1: " << dsu.rank[dsu.findPar(1)] << endl; // Expected: 2, 0
    cout << "Parent of 2: " << dsu.findPar(2) << ", Rank of 2: " << dsu.rank[dsu.findPar(2)] << endl; // Expected: 2, 0

    // Test Case 2
    cout << "\nTest Case 2:\n";
    dsu.unionByRank(2,3);
    dsu.unionByRank(4, 5);
    cout << "Parent of 1: " << dsu.findPar(1) << ", Rank of 1: " << dsu.rank[dsu.findPar(1)] << endl; // Expected: 4, 1
    cout << "Parent of 2: " << dsu.findPar(2) << ", Rank of 2: " << dsu.rank[dsu.findPar(2)] << endl; // Expected: 4, 1
    cout << "Parent of 3: " << dsu.findPar(3) << ", Rank of 3: " << dsu.rank[dsu.findPar(3)] << endl; // Expected: 4, 0
    cout << "Parent of 4: " << dsu.findPar(4) << ", Rank of 4: " << dsu.rank[dsu.findPar(4)] << endl; // Expected: 4, 1

    // Test Case 3
    cout << "\nTest Case 3:\n";
    dsu.unionByRank(6,7);
    dsu.unionByRank(5, 6);
    cout << "Parent of 1: " << dsu.findPar(1) << ", Rank of 1: " << dsu.rank[dsu.findPar(1)] << endl; // Expected: 4, 2
    cout << "Parent of 2: " << dsu.findPar(2) << ", Rank of 2: " << dsu.rank[dsu.findPar(2)] << endl; // Expected: 4, 2
    cout << "Parent of 3: " << dsu.findPar(3) << ", Rank of 3: " << dsu.rank[dsu.findPar(3)] << endl; // Expected: 4, 2
    cout << "Parent of 4: " << dsu.findPar(4) << ", Rank of 4: " << dsu.rank[dsu.findPar(4)] << endl; // Expected: 4, 2
    cout << "Parent of 5: " << dsu.findPar(5) << ", Rank of 5: " << dsu.rank[dsu.findPar(5)] << endl; // Expected: 4, 2
    cout << "Parent of 6: " << dsu.findPar(6) << ", Rank of 6: " << dsu.rank[dsu.findPar(6)] << endl; // Expected: 4, 2

    if(dsu.findPar(3)==dsu.findPar(7)){
        cout<<"Same Par"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }

    dsu.unionByRank(3,7);
    if(dsu.findPar(3)==dsu.findPar(7)){
        cout<<"Same Par"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }
}
