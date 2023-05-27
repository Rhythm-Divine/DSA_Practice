#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    string ans = "";
    vector<int> n={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> m =
        {
            "M",
            "CM",
            "D",
            "CD",
            "C",
            "XC",
            "L",
            "XL",
            "X",
            "IX",
            "V",
            "IV",
            "I",
        };

    for (int i = 0; num != 0; i++)
    {
        while (num >= n[i]){
            num-=n[i];
            ans=ans+m[i];
        }
    }
    return ans;
}
int main()
{
    int a = 2345;
    string ans = intToRoman(a);
    cout << ans << endl;
}