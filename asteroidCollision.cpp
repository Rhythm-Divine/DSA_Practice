#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && st.empty() || arr[i] < 0 && st.empty())
        {
            st.push(arr[i]);
        }
        else if (st.top() > 0 && arr[i] < 0)
        {
            while (abs(arr[i]) >= st.top())
            {

                if (st.top() == abs(arr[i]))
                {
                    st.pop();
                    break;
                }
                st.pop();
                if (st.empty())
                {
                    st.push(arr[i]);
                    break;
                }
            }
        }
        else if (st.top() < 0 && arr[i] > 0)
        {
            while (arr[i] >= abs(st.top()))
            {
                if (abs(st.top()) == arr[i])
                {
                    st.pop();
                    break;
                }
                st.pop();
                if (st.empty())
                {
                    st.push(arr[i]);
                    break;
                }
            }
        }
        else
        {
            st.push(arr[i]);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> x={-5,-10,8,-3,10};
    vector<int> v=asteroidCollision(x);

    for(auto i:v){
        cout<<i<<" ";
    }
}