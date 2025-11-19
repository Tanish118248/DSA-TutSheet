//a. Reverse the elements of an array
#include <iostream>
using namespace std;
void reverse(int arr[] , int n){
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
    cout<<"enter the elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reverse(arr, n);
    cout<<"Reversed Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


// b. Find the matrix multiplication
#include <iostream>
using namespace std;
int main() {
    int m, n, p, q;
    cout << "Enter rows and columns of first matrix: ";
    cin >> m >> n;
    cout << "Enter rows and columns of second matrix: ";
    cin >> p >> q;
    if (n != p) {
        cout << "Matrix multiplication not possible (columns of A != rows of B).\n";
        return 0;
    }
    int A[m][q];  
    int B[p][q];  
    cout << "Enter elements of first matrix (" << m << "x" << n << "):\n";
    int tempA[m][n]; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tempA[i][j];
        }
    }
    cout << "Enter elements of second matrix (" << p << "x" << q << "):\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            A[i][j] = 0;
            for (int k = 0; k < n; k++) {
                A[i][j] += tempA[i][k] * B[k][j];
            }
        }
    }
    cout << "Resultant Matrix (A = A × B):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}




// c. Find the Transpose of a Matrix
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[j][i] = mat[i][j];
        }
    }
    return result;
}
int main(){
    int n,m;
    cout<<"Enter the row and column of matrix : ";
    cin>>n>>m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout<<"enter the elements of array : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Original Matix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> transposed = transpose(mat);

    cout << "Transposed Matrix: " << endl;
    for(int i = 0; i < transposed.size(); i++){
        for(int j = 0; j < transposed[i].size(); j++){
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

