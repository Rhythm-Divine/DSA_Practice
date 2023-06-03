#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
    {
        return false;
    }
    if (n == 3)
    {
        if (arr[0] < arr[1] && arr[2] > arr[1])
            return true;
    }
    int i = 0;
    for (i; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            continue;
        }
        else
        {
            for (int j = i; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    continue;
                }
                else
                {
                    return false;
                }
                return true;
            }
            if (i == n - 1)
            {
                return false;
            }
        }
    }
    if (i == n - 1)
    {
        return false;
    }

    return true;
}

int main()
{
    vector<int> v = {0, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << boolalpha << validMountainArray(v) << endl;
}