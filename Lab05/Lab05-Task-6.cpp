#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> in;
    stack<int> out;
public:
    void enqueue(int item) {
        in.push(item);
    }
    int dequeue() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty()) return -1;
        int x = out.top();
        out.pop();
        return x;
    }
};

int main() {
    MyQueue q;
    q.enqueue('A');
    q.enqueue('B');
    cout << (char)q.dequeue() << endl;
    q.enqueue('C');
    cout << (char)q.dequeue() << endl;
    cout << (char)q.dequeue() << endl;
    return 0;
}
