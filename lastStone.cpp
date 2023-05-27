#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    if (stones.size() == 1)
    {
        return stones[0];
    }
    multiset<int> s(stones.begin(), stones.end());

    while (true)
    {
        cout<<"size: "<<s.size()<<endl;
        for(auto i:s){
            
            cout<<i<<" ";
        }
        cout<<endl;
        int num1 = *(s.rbegin());
        s.erase(num1);
        int num2 = *(s.rbegin());
        s.erase(num2);
        if (num1 == num2)
        {
            continue;
        }
        else
        {
            s.insert(num1 - num2);
        }
        if(s.size()<=1){
            break;
        }
    }
    
}

int main()
{
    vector<int> v = {2, 7, 4, 1, 8, 1,1};
   
    cout << lastStoneWeight(v) << endl;
}