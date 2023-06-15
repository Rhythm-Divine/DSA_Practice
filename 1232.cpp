#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    // y2-y1/x2-x1

    float m = float(coordinates[1][1] - coordinates[0][1]) / float(coordinates[1][0] - coordinates[0][0]);

    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    for (auto i : coordinates)
    {
        if (i == coordinates[0])
        {
            continue;
        }
        float m1 = float(i[1] - y1) / float(i[0] - x1);
        if ((m == INFINITY || m == -INFINITY )&& abs(m) == abs(m1))
        {
            continue;
        }
        if (m1 != m)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> v = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};
    cout << boolalpha << checkStraightLine(v) << endl;
    cout << INFINITY;
}