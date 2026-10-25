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
 
void radixSort(int a[], int n) {
    int maxVal = getMax(a, n);
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
        pass++;
        cout << "After pass " << pass << ": ";
        printArray(a, n);
    }
}
 
int main() {
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = 7;
    cout << "Original array: ";
    printArray(arr, n);
    radixSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
