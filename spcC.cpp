#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int q;
    cin >> q;
    int temp,temp1;

    vector<int> func(n);
    vector<int> qry;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        func.push_back(temp);
    }
    sort(func.begin(), func.end());
    for (int i = 0; i < q; i++)
    {
        cin >> temp1;

        qry.push_back(temp1);
    }
    for(auto i:qry){
        cout<<i<<" ";
    }
    cout<<endl;
    for (int i = 0; i < q; i++)
    {
        if (qry[i] < 0)
        {
            if (n % 2 == 0)
            {
                cout << "POSITIVE" << endl;
            }
            else
            {
                cout << "NEGATIVE" << endl;
            }
        }
        else if (qry[i] > func[n - 1])
        {
            cout << "POSITIVE" << endl;
        }
        else
        {
            long long int product = 1;
            int k = 0;
            while (k < q - 1)
            {
                product *= (qry[i] - func[k]);
                k++;
            }
            if (product > 0)
            {
                cout << "POSITIVE" << endl;
            }
            else if (product < 0)
            {
                cout << "POSITIVE" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}