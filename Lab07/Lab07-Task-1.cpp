Claude
Q1 · CPP
#include <iostream>
using namespace std;
 
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
void merge(int a[], int l, int m, int r, int n, int &mergeCount) {
    int tmp[100];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int x = 0; x < k; x++) a[l + x] = tmp[x];
    mergeCount++;
    cout << "After merge " << mergeCount << ": ";
    printArray(a, n);
}
 
void mergeSort(int a[], int l, int r, int n, int &mergeCount) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m, n, mergeCount);
    mergeSort(a, m + 1, r, n, mergeCount);
    merge(a, l, m, r, n, mergeCount);
}
 
int main() {
    int a[] = {78, 45, 92, 63, 45, 88, 51, 70};
    int n = 8;
    int mergeCount = 0;
    cout << "Original array: ";
    printArray(a, n);
    mergeSort(a, 0, n - 1, n, mergeCount);
    cout << "Sorted array: ";
    printArray(a, n);
    cout << "Total merge operations: " << mergeCount << endl;
    return 0;
}
 
Claude finished the response

