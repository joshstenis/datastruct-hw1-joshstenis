#include <iostream>
using namespace std;

int x[30];
int xSize = sizeof(x)/sizeof(x[0]);
int y[30];
int ySize = sizeof(y)/sizeof(y[0]);

/**
 * Outputs a given int array as a oneline string
 * @param arr Given int array, in theory represents a sparse matrix
 */
void outputMatrix(int arr[]) {
    cout << x[0];
    for(int i=1; i < xSize; i++) {
        cout << " " << x[i];
    } cout << endl;
}

/**
 * Copies a given int array.
 * @param arr Given int array to be copied
 */
void copyToX(int arr[]) {
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i < arrSize; i++) {
        x[i] = arr[i];
    }
}

/**
 * Populates a given array with the contents of a given string.
 * @param str Given string to be put into array
 * @param arr Given array to be populated with the string (removes spaces)
 */
void populateArray(string str, int arr[]) {
    int j = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            arr[j++] = (int)str[i] - 48;        // Method was using unicode values, so the constant 48 was found to gain the desired value
    }
}

/**
 * Transposes a given array.
 * Outputs transposition in efficient representation.
 * @param arr Given array to be transposed. Assumes efficient representation
 */
void transpose(int arr[]) {
    copyToX(arr);

    outputMatrix(x);
    int j = 0;
    for(int i=0; i < xSize; i+=3) {  // swaps row and column values for each trio
        arr[i] = (arr[i] ^ arr[i+1]) ^ (arr[i+1] = arr[i]);
    }

    int *tmp;
    for(int i=0; i < xSize; i+=3) {    // bubble sort by row-column-value trios
        for(int j=i+3; j < xSize; j+=3) {
            tmp = &arr[j];
            if(arr[j] < arr[i] || (arr[j] == arr[i] && arr[j+1] < arr[i+1])) {       // if rows OR columns are in wrong order
                arr[i] = arr[j];
                arr[i+1] = arr[j+1];
                arr[i+2] = arr[j+2];

                arr[j] = *tmp++;
                arr[j+1] = *tmp++;
                arr[j+2] = *tmp++;
            }
        }
    } outputMatrix(arr);
}

/**
 * Multiplies two matrices.
 */
void multiply() {
    //
}

/**
 * Calculates the sum of two matrices.
 */
void sum(int x[], int y[]) {
    int sum[60];

    
    outputMatrix(sum);
}

int main() {
    // Task 1
    string rawMatrix;
    getline(cin, rawMatrix);
    populateArray(rawMatrix, x);
    transpose(x);

    // Task 2
    // getline(cin, rawMatrix);
    // populateArray(rawMatrix, y);
    // sum(x, y);

    // Task 3
}