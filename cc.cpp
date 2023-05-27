#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            int count = 0;
            string s;
            cin >> s;
            string f;
            cin >> f;

            for (int i = 0; i < n; i++)
            {
                if (s[i] != f[i])
                {
                    count++;
                }
            }
            if (count % 2 == 0)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}
