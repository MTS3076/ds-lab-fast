#include <iostream>
using namespace std;

int main()
{
    int arr[] = {55, 61, 67, 72, 78, 81, 80, 85};
    int n = 8;
    int comparisons = 0;
    int swaps = 0;
    int passes = 0;

    for (int pass = 0; pass < n - 1; pass++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - pass; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }

        passes++;

        if (!swapped)
            break;
    }

    cout << "Array becomes sorted after Pass: " << passes << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Standard Bubble Sort Passes: " << n - 1 << endl;

    int standardComparisons = (n - 1) * n / 2;
    cout << "Standard Bubble Sort Comparisons: " << standardComparisons << endl;

    return 0;
}
