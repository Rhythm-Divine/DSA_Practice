#include <bits/stdc++.h>
using namespace std;
int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}
bool equationsPossible(vector<string> &equations)
{
    int n = equations.size();
    vector<int> parent(26);
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }
    for (auto x : equations)
    {
        if (x[1] == '=')
        {
            parent[findParent(x[3] - 'a', parent)] = findParent(x[0] - 'a', parent);
        }
    }

    for (auto x : equations)
    {

        if (x[1] == '!' && findParent(x[3] - 'a', parent) == findParent(x[0] - 'a', parent))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<string> equation={"b!=a","a==b"};
    bool flag=equationsPossible(equation);
    cout<<boolalpha<<flag<<endl;
}