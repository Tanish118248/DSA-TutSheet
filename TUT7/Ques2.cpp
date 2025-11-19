#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        swap(arr[left], arr[minIndex]);
        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

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


