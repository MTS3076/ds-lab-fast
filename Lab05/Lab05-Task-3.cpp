#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef queue<string> Queue;

void reverseFirstK(Queue &q, int k) {
    stack<string> s;
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    int n = (int)q.size() - k;
    for (int i = 0; i < n; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    Queue q;
    for (int i = 1; i <= 7; i++) q.push("J" + to_string(i));
    reverseFirstK(q, 3);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
