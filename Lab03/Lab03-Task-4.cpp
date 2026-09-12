#include <iostream>
using namespace std;

int main()
{
    int arr[] = {90, 20, 80, 30, 70, 40, 60, 50, 10};
    int n = 9;

    int totalComparisons = 0;
    int totalShifts = 0;

    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        int comparisons = 0;
        int shifts = 0;

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap)
            {
                comparisons++;

                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                    shifts++;
                }
                else
                {
                    break;
                }
            }

            arr[j] = temp;
        }

        totalComparisons += comparisons;
        totalShifts += shifts;

        cout << "Gap: " << gap << endl;

        cout << "Array: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Shifts: " << shifts << endl;
        cout << endl;
    }

    cout << "Total Comparisons: " << totalComparisons << endl;
    cout << "Total Shifts: " << totalShifts << endl;

    return 0;
}
