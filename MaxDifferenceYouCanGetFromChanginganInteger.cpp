#include <bits/stdc++.h>
using namespace std;

int maxDiff(int num)
{
    string maxN = to_string(num);
    string minN = to_string(num);
    char t1, t2;
    bool flag;
    for (int i = 0; i < maxN.size(); i++)
    {
        if (maxN[i] != '9')
        {
            t1 = maxN[i];
            break;
        }
    }
    for (int i = 0; i < maxN.size(); i++)
    {
        if (maxN[i] == t1)
        {
            maxN[i] = '9';
        }
    }
    cout << maxN << endl;
    if (minN[0] != '1')
    {
        t2 = minN[0];
        for (int i = 0; i < minN.size(); i++)
        {
            if (minN[i] == t2)
            {
                minN[i] = '1';
            }
        }
    }

    else
    {
        for (int i = 1; i < minN.size(); i++)
        {
            if (minN[i] != '0' && minN[i]!= '1')
            {
                t2 = minN[i];
                break;
            }
        }
        for (int i = 1; i < minN.size(); i++)
        {
            if (minN[i] == t2)
            {
                minN[i] = '0';
            }
        }
    }

    cout << minN << endl;
    int a = stoi(maxN);
    int b = stoi(minN);
    return a - b;
}

int main()
{
    cout << maxDiff(11111) << endl;
}