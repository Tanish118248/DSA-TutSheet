#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        // Find min and max in the current unsorted range
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum with the leftmost element
        swap(arr[left], arr[minIndex]);

        // If we swapped the maximum element into the minIndex position,
        // we need to update its index
        if (maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum with the rightmost element
        swap(arr[right], arr[maxIndex]);

        // Narrow the range
        left++;
        right--;
    }
}

// Function to display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal array: ";
    display(arr, n);

    improvedSelectionSort(arr, n);

    cout << "\nArray after Improved Selection Sort: ";
    display(arr, n);

    return 0;
}


