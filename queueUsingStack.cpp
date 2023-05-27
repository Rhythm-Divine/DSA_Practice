#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue()
    {
        stack<int> *stk1 = new stack<int>();
        stack<int> *stk2 = new stack<int>();
    }

    void push(int x)
    {
        stk1.push(x);
    }

    int pop()
    {
        peek();
        int temp = stk2.top();
        stk2.pop();
        return temp;
    }

    int peek()
    {
        if(stk2.empty()) {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
        }
    }
    return stk2.top();
    }

    bool empty()
    {
        if (stk2.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);

    // for(int i=0;i<=obj->stk1.size();i++){
    //     cout<<obj->stk1.top()<<endl;
    //     obj->stk1.pop();
    // }
    // cout << endl;
    cout << obj->peek() << endl;
    //   for(int i=0;i<obj->stk2.size();i++){
    //     cout<<obj->stk2.top()<<endl;
    //     obj->stk2.pop();
    // }
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
}