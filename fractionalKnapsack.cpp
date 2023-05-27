#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    double x = double(a.second) /double( a.first);
    double y = double(b.second) / double(b.first); 
    return x>y;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    double val;
    sort(items.begin(), items.end(), comparator);
   
    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            val += items[i].second;
            w -= items[i].first;
        }
        else
        {

            val += (double(items[i].second) / double(items[i].first)) * double(w);
            break;
        }
    }
    return val;
}

int main()
{
    pair<int,int> p1={50,40};
    pair<int,int> p2={40,50};
    pair<int,int> p3={90,25};
    pair<int,int> p4={120,100};
    pair<int,int> p5={10,30};
    pair<int,int> p6={200,45};

    vector<pair<int,int>> v={p1,p2,p3,p4,p5,p6};
    double ans=maximumValue(v,6,200);
    cout<<ans<<endl;
}