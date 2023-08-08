#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


    ll getC(vector<int> &v1, vector<int> &v2, int mid)
{
    ll cnt = 0;
set<pair<int, int>> st;
    int j = v2.size() - 1;
    for (auto i : v1)
    {
        while (j >= 0)
        {
            if (i * v2[j] <= mid && st.find({i, v2[j]}) == st.end())
            {
                cnt += j + 1;
                st.insert({i, v2[j]});
                break;
            }
            else
            {
                j--;
            }
        }
    }
    return cnt;
}
ll kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    vector<int> neg1;
    vector<int> neg2;
    vector<int> pos1;
    vector<int> pos2;
    bool isPos;
    // ll lowest=(neg1[0]*pos2[pos2.size()-1]<neg2[0]*pos1[pos1.size()-1])?neg1[0]*pos2[pos2.size()-1]:neg2[0]*pos1[pos1.size()-1];
    // ll highest=(pos1[pos1.size()-1]*pos2[pos2.size()-1]<neg1[0]*neg2[0])?neg1[0]*neg2[0]:pos1[pos1.size()-1]*pos2[pos2.size()-1];
    ll lowest = -1e10;
    ll highest = 1e10 + 1;
    for (auto i : nums1)
    {
        if (i >= 0)
        {
            pos1.push_back(i);
        }
        neg1.push_back(i);
    }
    for (auto i : nums2)
    {
        if (i >= 0)
        {
            pos2.push_back(i);
        }
        neg2.push_back(i);
    }

    ll negP = neg1.size() * pos2.size() + neg2.size() * pos1.size();
    if (negP < k)
    {
        k -= negP;
        isPos = true;
    }
    //-3 -2 -1
    //-6 -5 -4
    if (isPos)
    {
        reverse(neg1.begin(), neg1.end());
        reverse(neg2.begin(), neg2.end());
    }
    else
    {
        reverse(pos1.begin(), pos1.end());
        reverse(pos2.begin(), pos2.end());
    }

    while (lowest < highest)
    {
        ll mid = lowest + (highest - lowest) / 2;
        ll count = !isPos ? getC(neg1, neg2, mid) + getC(pos1, pos2, mid) : getC(neg1, pos2, mid) + getC(neg2, pos1, mid);
        if (count >= k)
        {
            highest = mid;
        }
        else
        {
            lowest = mid + 1;
        }
    }
    return highest;
}

int main()
{
    vector<int> num1 = {-2,-1,0,1,2};
    vector<int> num2 = {-3,-1,2,4,5};
    cout << kthSmallestProduct(num1, num2, 3) << endl;
}