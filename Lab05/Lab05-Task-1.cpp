#include <iostream>
using namespace std;

const int CAP = 8;
int st[CAP];
int topIdx = -1;

void show() {
    if (topIdx == -1) cout << "Stack is empty" << endl;
    else cout << "Top: " << st[topIdx] << endl;
}

void push(int x) {
    if (topIdx == CAP - 1) {
        for (int i = 1; i < CAP; i++) st[i - 1] = st[i];
        topIdx--;
    }
    st[++topIdx] = x;
    cout << "Operation " << x << " -> ";
    show();
}

void undo() {
    if (topIdx == -1) {
        cout << "Undo -> Stack is empty, nothing to undo" << endl;
        return;
    }
    topIdx--;
    cout << "Undo -> ";
    show();
}

int main() {
    int ops[] = {12, 25, 17, 31, 44, 19};
    for (int x : ops) push(x);
    undo();
    undo();
    undo();
    push(52);
    undo();
    undo();
    cout << "Remaining (top to bottom): ";
    for (int i = topIdx; i >= 0; i--) cout << st[i] << " ";
    cout << endl;
    return 0;
}
