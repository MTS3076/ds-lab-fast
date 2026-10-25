#include <iostream>
using namespace std;
 
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
 
int partition(int a[], int low, int high, int n, int &partitionCount) {
    int pivot = a[high];
    partitionCount++;
    cout << "Partition " << partitionCount << ": pivot = " << pivot
         << ", low = " << low << ", high = " << high << endl;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    cout << "Array after partition: ";
    printArray(a, n);
    return i + 1;
}
 
void quickSort(int a[], int low, int high, int n, int &partitionCount) {
    if (low < high) {
        int p = partition(a, low, high, n, partitionCount);
        quickSort(a, low, p - 1, n, partitionCount);
        quickSort(a, p + 1, high, n, partitionCount);
    }
}
 
int main() {
    int a[] = {40, 20, 70, 10, 60, 30, 50};
    int n = 7;
    int partitionCount = 0;
    cout << "Original array: ";
    printArray(a, n);
    quickSort(a, 0, n - 1, n, partitionCount);
    cout << "Sorted array: ";
    printArray(a, n);
    cout << "Total partition operations: " << partitionCount << endl;
    return 0;
}
