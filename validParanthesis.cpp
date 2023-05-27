#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int n = s.length();
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else
        {
            if (st.empty() && (i == ')' || i == ']' ||i == '}'))
            {
                return false;
            }else{
                if (i == ')' && st.top() != '(' || i == ']' && st.top() != '[' || i == '}' && st.top() != '{')
                {
                    return false;
                }
                else
                {

                    st.pop();
                }
            }

        }
    }
    return st.empty();
}
int main()
{
    string s = ")";
    cout << boolalpha << isValid(s) << endl;
}