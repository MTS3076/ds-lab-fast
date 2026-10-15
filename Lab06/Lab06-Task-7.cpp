#include <iostream>
using namespace std;

int nums[5] = {2, 3, 5, 6, 8};
bool chosen[5] = {false};
int target = 9;

bool solve(int index, int sum) {
    if (sum == target) return true;
    if (index == 5 || sum > target) return false;

    chosen[index] = true;
    if (solve(index + 1, sum + nums[index])) return true;

    chosen[index] = false;
    return solve(index + 1, sum);
}

int main() {
    if (solve(0, 0)) {
        cout << "Subset with sum " << target << ": ";
        for (int i = 0; i < 5; i++)
            if (chosen[i]) cout << nums[i] << " ";
        cout << endl;
    } else {
        cout << "No subset with sum " << target << " exists." << endl;
    }
    return 0;
}
