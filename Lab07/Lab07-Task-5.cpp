#include <iostream>
using namespace std;
 
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
int partition(int a[], int low, int high, int n, int &comparisons) {
    int pivot = a[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (a[j] < pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[low]; a[low] = a[i]; a[i] = t;
    cout << "Pivot: " << pivot << " | Array: ";
    printArray(a, n);
    return i;
}
 
void quickSort(int a[], int low, int high, int n, int &comparisons) {
    if (low < high) {
        int p = partition(a, low, high, n, comparisons);
        quickSort(a, low, p - 1, n, comparisons);
        quickSort(a, p + 1, high, n, comparisons);
    }
}
 
int main() {
    int a[] = {55, 25, 75, 15, 65, 35, 45};
    int n = 7;
    int comparisons = 0;
    cout << "Original array: ";
    printArray(a, n);
    quickSort(a, 0, n - 1, n, comparisons);
    cout << "Sorted array: ";
    printArray(a, n);
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
