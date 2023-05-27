#include <bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissing(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    long long int trueSum = (n * (n + 1))/2;
    long long int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }

    long long int trueProduct = (n * (n + 1) * (2 * n + 1))/6;
    long long int product=0;
    for (auto i : nums)
    {
        product += i*i;
    }

    long long int diff = trueSum - sum;                // diff of missing no. and duplicate no.
    long long int diffSquares = trueProduct - product; // diff of square of missing no. and square of duplicate no.

    long long int sumOfNo = diffSquares / diff;
    int firstNo = (sumOfNo + diff) / 2;
    int secondNo = max<long long int>(sumOfNo, firstNo) - min<long long int>(sumOfNo, firstNo);
    if(find(nums.begin(),nums.end(),firstNo)==nums.end()){
        ans.push_back(secondNo);
    }
    ans.push_back(firstNo);
    
    return ans;
}
int main()
{
    vector<int> x = {1, 3 ,5 ,4 ,4};
    vector<int> ans = repeatAndMissing(x);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}