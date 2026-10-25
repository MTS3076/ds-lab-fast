#include <iostream>
using namespace std;
 
void printArray(const char *label, int a[], int n) {
    cout << label;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
void printCount(const char *label, int c[]) {
    cout << label;
    for (int i = 0; i < 10; i++) cout << c[i] << " ";
    cout << endl;
}
 
int main() {
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = 7;
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        pass++;
        int count[10] = {0};
        int output[7];
        for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
        cout << "Pass " << pass << " (digit place " << exp << ")" << endl;
        printCount("Frequency count:  ", count);
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        printCount("Cumulative count: ", count);
        for (int i = n - 1; i >= 0; i--) {
            int d = (arr[i] / exp) % 10;
            output[--count[d]] = arr[i];
        }
        printArray("Output array:     ", output, n);
        for (int i = 0; i < n; i++) arr[i] = output[i];
        cout << endl;
    }
    printArray("Sorted array: ", arr, n);
    return 0;
}
