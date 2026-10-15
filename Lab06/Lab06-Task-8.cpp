#include <iostream>
using namespace std;

char chars[4] = {'A', 'B', 'C', 'D'};
char perm[4];
bool used[4] = {false};
int total = 0;

void solve(int pos) {
    if (pos == 4) {
        total++;
        for (int i = 0; i < 4; i++) cout << perm[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!used[i]) {
            used[i] = true;
            perm[pos] = chars[i];
            solve(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    solve(0);
    cout << "Total: " << total << endl;
    return 0;
}
