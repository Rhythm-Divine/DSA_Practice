#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int arr[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        if (arr[0] == arr[1] && arr[1] == arr[2])
        {
            cout << "yes" << endl;
        }
        else if (arr[0] == arr[1] && arr[1] != arr[2])
        {
            if (arr[1] < arr[2])
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (arr[0] != arr[1] && arr[1] == arr[2])
        {
            if (arr[0] > arr[1])
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (arr[0] != arr[1] && arr[0] == arr[2])
        {
            if (arr[1] > arr[2])
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
        {
            cout << "no" << endl;
        }
    }
}