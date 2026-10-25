#include <iostream>
using namespace std;
 
void printRange(int a[], int s, int e) {
    for (int i = s; i <= e; i++) cout << a[i] << " ";
}
 
void merge(int a[], int l, int m, int r, int &comparisons) {
    int tmp[100];
    int i = l, j = m + 1, k = 0;
    cout << "Left: ";
    printRange(a, l, m);
    cout << "| Right: ";
    printRange(a, m + 1, r);
    cout << endl;
    while (i <= m && j <= r) {
        comparisons++;
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int x = 0; x < k; x++) a[l + x] = tmp[x];
}
 
void mergeSort(int a[], int l, int r, int &comparisons) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m, comparisons);
    mergeSort(a, m + 1, r, comparisons);
    merge(a, l, m, r, comparisons);
}
 
int main() {
    int a[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = 8;
    int comparisons = 0;
    mergeSort(a, 0, n - 1, comparisons);
    cout << "Sorted prices: ";
    printRange(a, 0, n - 1);
    cout << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
