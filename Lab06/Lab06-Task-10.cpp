#include <iostream>
using namespace std;

char grid[3][3] = {
    {'C', 'A', 'R'},
    {'X', 'T', 'O'},
    {'B', 'E', 'D'}
};
bool visited[3][3] = {false};
char word[3] = {'C', 'A', 'T'};
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool search(int r, int c, int idx) {
    if (idx == 3) return true;
    if (r < 0 || r >= 3 || c < 0 || c >= 3) return false;
    if (visited[r][c] || grid[r][c] != word[idx]) return false;

    visited[r][c] = true;
    for (int d = 0; d < 4; d++)
        if (search(r + dr[d], c + dc[d], idx + 1)) {
            visited[r][c] = false;
            return true;
        }
    visited[r][c] = false;
    return false;
}

int main() {
    bool found = false;
    for (int i = 0; i < 3 && !found; i++)
        for (int j = 0; j < 3 && !found; j++)
            if (search(i, j, 0)) found = true;

    if (found) cout << "CAT exists in the grid." << endl;
    else cout << "CAT does not exist in the grid." << endl;
    return 0;
}
