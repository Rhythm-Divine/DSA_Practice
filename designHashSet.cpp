#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
public:
    vector<int> v;
    MyHashSet()
    {
        v.resize(1e6 + 1, 0);
    }

    void add(int key)
    {
        if (v[key] == 0)
        {
            v[key] = 1;
        }
    }

    void remove(int key)
    {
        if (v[key] == 1)
        {
            v[key] = 0;
        }
    }

    bool contains(int key)
    {
        if (v[key] == 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    
}