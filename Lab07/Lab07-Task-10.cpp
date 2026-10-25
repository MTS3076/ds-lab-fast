#include <iostream>
using namespace std;
 
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
int getMax(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}
 
void countingSort(int a[], int n, int exp) {
    int output[100];
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[--count[d]] = a[i];
    }
    for (int i = 0; i < n; i++) a[i] = output[i];
}
 
int main() {
    int a[] = {7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
    int n = 10;
    int maxVal = getMax(a, n);
    int passes = 0;
    for (int t = maxVal; t > 0; t /= 10) passes++;
    cout << "Original array: ";
    printArray(a, n);
    cout << "Maximum number of digit passes: " << passes << endl;
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
        pass++;
        cout << "After pass " << pass << ": ";
        printArray(a, n);
    }
    cout << "Sorted array: ";
    printArray(a, n);
    return 0;
}
