#include <iostream>
using namespace std;

int main()
{
    int arr[] = {45, 12, 78, 34, 23, 90};
    int n = 6;
    int comparisons = 0;
    int swaps = 0;

    for (int pass = 0; pass < n - 1; pass++)
    {
        for (int j = 0; j < n - 1 - pass; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }

        cout << "Pass " << pass + 1 << ": ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    cout << "Number of Passes: " << n - 1 << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;

    return 0;
}
