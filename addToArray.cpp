#include <bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
    int n = ceil(log10(k));
    int sz = num.size() - 1;
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        if (num[sz - i] + k % 10 + carry > 9)
        {
            cout<<k%10<<" "<<num[sz-i]<<" "<<num[sz - i] + (k % 10)<<endl;
            carry = (num[sz - i] + k % 10) / 10;
            num[sz - i] = (num[sz - i] + k % 10) % 10;
            
        }
        else
        {
            cout<<"else"<<endl;
            cout<<k%10<<" "<<num[sz-i]<<" "<<num[sz - i] + (k % 10)<<endl;
            num[sz - i] += k % 10 + carry;
            carry = 0;
        }
        k /= 10;
    }
    if (carry != 0)
    {
        num.insert(num.begin(),carry);
    }
    return num;
}

int main()
{
    vector<int> x = {2, 1, 5};
    vector<int> ans = addToArrayForm(x, 806);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}