#include <iostream>
using namespace std;

const int SIZE = 6;
int q[SIZE];
int frontIdx = 0;
int rearIdx = -1;
int cnt = 0;

void enqueue(int id) {
    if (cnt == SIZE) {
        cout << "Queue full" << endl;
        return;
    }
    rearIdx = (rearIdx + 1) % SIZE;
    q[rearIdx] = id;
    cnt++;
}

void dequeue() {
    if (cnt == 0) {
        cout << "Queue empty" << endl;
        return;
    }
    frontIdx = (frontIdx + 1) % SIZE;
    cnt--;
}

int main() {
    for (int id = 101; id <= 106; id++) enqueue(id);
    for (int i = 0; i < 3; i++) dequeue();
    for (int id = 107; id <= 109; id++) enqueue(id);
    for (int i = 0; i < 2; i++) dequeue();
    enqueue(110);
    dequeue();
    enqueue(111);
    enqueue(112);

    cout << "Boarding order: ";
    for (int i = 0; i < cnt; i++) cout << q[(frontIdx + i) % SIZE] << " ";
    cout << endl;
    cout << "Front: " << frontIdx << endl;
    cout << "Rear: " << rearIdx << endl;
    return 0;
}
