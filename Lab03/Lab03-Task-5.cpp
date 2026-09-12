#include <iostream>
using namespace std;

int main()
{
    int n;

    do
    {
        cout << "Enter number of students (5-15): ";
        cin >> n;

        if (n < 5 || n > 15)
            cout << "Invalid number of students. Try again." << endl;

    } while (n < 5 || n > 15);

    int marks[15];

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter marks for student " << i + 1 << " (0-100): ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
                cout << "Invalid marks. Try again." << endl;

        } while (marks[i] < 0 || marks[i] > 100);
    }

    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = marks[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (marks[j] < key)
            {
                marks[j + 1] = marks[j];
                j--;
                shifts++;
            }
            else
            {
                break;
            }
        }

        marks[j + 1] = key;
    }

    int highest = marks[0];
    int lowest = marks[n - 1];

    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += marks[i];

    double average = sum / n;

    bool highAchiever = false;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 90)
        {
            highAchiever = true;
            break;
        }
    }

    cout << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Shifts: " << shifts << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << average << endl;

    cout << "Sorted Marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    cout << endl;

    if (highAchiever)
        cout << "High Achiever(s) Present" << endl;
    else
        cout << "No High Achiever" << endl;

    return 0;
}
