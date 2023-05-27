#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int arr[s];
        int temp[s];
        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
        }

        for (int i = s - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    cout << endl;
}