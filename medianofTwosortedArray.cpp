#include <bits/stdc++.h>
using namespace std;

 double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> temp;
    int s = nums1.size() + nums2.size();
    for (int i = 0; i < nums1.size(); i++)
    {

        temp.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {

        temp.push_back(nums2[i]);
    }

    sort(temp.begin(),temp.end());
    double ans;
    if(s%2==0){
        ans=double(temp.at(s/2)+temp.at(s/2-1))/2;

    }else{
        ans=double(temp.at(s/2));
    }
    return ans;
    
}
int main()
{
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    double x = findMedianSortedArrays(v1, v2);

    cout<<x<<endl;
}