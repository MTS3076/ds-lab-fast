#include <iostream>
using namespace std;
 
void printArray(const char *label, int a[], int n) {
    cout << label;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
int getMax(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}
 
void countingSort(int a[], int n, int exp, int pass) {
    int output[100];
    int count[10] = {0};
    cout << "Pass " << pass << " (exp = " << exp << ")" << endl;
    printArray("Original array:   ", a, n);
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    printArray("Frequency count:  ", count, 10);
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    printArray("Cumulative count: ", count, 10);
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[--count[d]] = a[i];
    }
    printArray("Output array:     ", output, n);
    for (int i = 0; i < n; i++) a[i] = output[i];
    printArray("Copied back:      ", a, n);
    cout << endl;
}
 
void radixSort(int a[], int n) {
    int maxVal = getMax(a, n);
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        pass++;
        countingSort(a, n, exp, pass);
    }
    cout << "Total digit passes: " << pass << endl;
}
 
int main() {
    int trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
    int n = 12;
    printArray("Initial array: ", trackingIDs, n);
    cout << endl;
    radixSort(trackingIDs, n);
    printArray("Final sorted array: ", trackingIDs, n);
    return 0;
}
