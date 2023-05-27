#include <bits/stdc++.h>
using namespace std;


int findMedian(vector<vector<int>> &mat)
{
    int mn=INT32_MAX;
    int mx=INT32_MIN;
    int count=0;
   for(auto i:mat){
    count++;
    mn=min(mn,*min_element(i.begin(),i.end()));
    mx=max(mx,*max_element(i.begin(),i.end()));
   }
   int midPos=((mat[0].size()*count)+1)/2;
    while(mn<=mx){
        int mid=mn+(mx-mn)/2;
        int ele=0;
        for(auto i:mat){
        int noOfEle=upper_bound(i.begin(),i.end(),mid)-i.begin();
        ele+=noOfEle;
        }
        if(ele>=midPos){
            mx=mid-1;
        }else{
            mn=mid+1;
        }
        
    }
    return mn;

}

int main()
{
    vector<vector<int>> mat = { { 9,11,15 }, { 5,6,8 }, { 1,2,3 } };
    int median = findMedian(mat);

//       for(auto i:mat){
//     count++;
//     // mn=min(mn,*min_element(i.begin(),i.end()));
//     // mx=max(mx,*max_element(i.begin(),i.end()));
//    }
   
    cout << "The median is: " << median << endl;
    return 0;
}




