#include <iostream>
using namespace std;
 
int recursiveCalls = 0, mergeOps = 0, comparisons = 0;
 
void merge(int *a, int *tmp, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        comparisons++;
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int x = l; x <= r; x++) a[x] = tmp[x];
    mergeOps++;
}
 
void mergeSort(int *a, int *tmp, int l, int r) {
    recursiveCalls++;
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, tmp, l, m);
    mergeSort(a, tmp, m + 1, r);
    merge(a, tmp, l, m, r);
}
 
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Error: n must be greater than 0" << endl;
        return 1;
    }
    int *a = new int[n];
    int *tmp = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, tmp, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    cout << "Recursive calls: " << recursiveCalls << endl;
    cout << "Merge operations: " << mergeOps << endl;
    cout << "Comparisons: " << comparisons << endl;
    delete[] a;
    delete[] tmp;
    return 0;
}
