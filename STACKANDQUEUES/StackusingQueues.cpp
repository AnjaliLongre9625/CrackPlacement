#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int ci = q2.front();
        q2.pop();
        return ci;
    }

    int top()
    {
        return q2.front();
    }

    bool empty()
    {
        return q2.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    // Output the results to verify correctness
    cout << "Popped element: " << param_2 << endl;
    cout << "Top element: " << param_3 << endl;
    cout << "Is stack empty: " << boolalpha << param_4 << endl;

    delete obj;
    return 0;
}
