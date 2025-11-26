#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;        
    int left = 2*i + 1;     
    int right = 2*i + 2;    

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSortIncreasing(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);    
        heapify(arr, i, 0);     
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSortIncreasing(arr, n);

    cout << "Sorted array in Increasing Order: ";
    for (int x : arr)
        cout << x << " ";
}



// #include <iostream>
// using namespace std;
// void minHeapify(int arr[], int n, int i) {
//     int smallest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;
//     if (left < n && arr[left] < arr[smallest])
//         smallest = left;
//     if (right < n && arr[right] < arr[smallest])
//         smallest = right;
//     if (smallest != i) {
//         swap(arr[i], arr[smallest]);
//         minHeapify(arr, n, smallest);
//     }
// }
// void heapSortDecreasing(int arr[], int n) {
//     for (int i = n/2 - 1; i >= 0; i--)
//         minHeapify(arr, n, i);
//     for (int i = n-1; i >= 0; i--) {
//         swap(arr[0], arr[i]);    
//         minHeapify(arr, i, 0);
//     }
// }
// int main() {
//     int arr[] = {12, 3, 19, 7, 1, 15};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     heapSortDecreasing(arr, n);

//     cout << "Sorted array in Decreasing Order: ";
//     for (int x : arr)
//         cout << x << " ";
// }

