#include <bits/stdc++.h>
using namespace std;
#define debugmp(v)                                  \
    for (auto i : v)                                \
    {                                               \
        cout << i.first << "-->" << i.second << endl; \
    }

std::vector<int> sortarr(const std::vector<int> &nums, const std::vector<int> &moveFrom, const std::vector<int> &moveTo)
{
  unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 0; i < moveFrom.size(); ++i) {
        if (s.count(moveFrom[i])) {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
    }
    vector<int> result(s.begin(), s.end());
    sort(result.begin(), result.end());

    return result;

}
int main()
{   
    vector<int> a={1,1,3,3};
    vector<int> b={1,3};
    vector<int> c={2,2};
    
    vector<int> x = sortarr(a,b,c);
    for (auto i : x)
    {
        cout << i << " ";
    }
}