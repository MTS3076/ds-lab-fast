#include <iostream>
#include <string>
using namespace std;

string vertices[4] = {"A", "B", "C", "D"};
string colors[3] = {"Red", "Green", "Blue"};
string result[4];  // empty string = uncolored

bool isSafe(int i, const string& color) {
    int offsets[4] = {-2, -1, 1, 2};
    for (int k = 0; k < 4; k++) {
        int j = i + offsets[k];
        if (j >= 0 && j < 4 && result[j] == color)
            return false;
    }
    return true;
}

bool solve(int i) {
    if (i == 4) return true;            // all vertices colored
    for (int c = 0; c < 3; c++) {
        if (isSafe(i, colors[c])) {
            result[i] = colors[c];      // choose
            if (solve(i + 1)) return true;
            result[i] = "";             // backtrack
        }
    }
    return false;
}

int main() {
    if (solve(0)) {
        for (int i = 0; i < 4; i++)
            cout << vertices[i] << ": " << result[i] << endl;
    } else {
        cout << "No valid coloring exists." << endl;
    }
    return 0;
}
