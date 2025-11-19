#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// a) SELECTION SORT
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout << "\nArray after Selection Sort: ";
    display(arr, n);
}

// b) INSERTION SORT
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "\nArray after Insertion Sort: ";
    display(arr, n);
}

// c) BUBBLE SORT
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\nArray after Bubble Sort: ";
    display(arr, n);
}

int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    do {
        cout << "\n===== Sorting Menu =====";
        cout << "\n1. Selection Sort";
        cout << "\n2. Insertion Sort";
        cout << "\n3. Bubble Sort";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        int tempArr[100];
        for (int i = 0; i < n; i++) tempArr[i] = arr[i]; 

        switch (choice) {
            case 1: selectionSort(tempArr, n); break;
            case 2: insertionSort(tempArr, n); break;
            case 3: bubbleSort(tempArr, n); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

