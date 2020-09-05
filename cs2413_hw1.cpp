#include <iostream>
using namespace std;

int x[30];
int xSize = sizeof(x)/sizeof(x[0]);
int y[30];
int ySize = sizeof(y)/sizeof(y[0]);


// General use version of strToArray() and arrayToString()
// 
// int *strToArray(string str) {
//     static int sparse[30];
//     int sparseLen = 0;
//     for(int i=0; i < str.length(); i++) {
//         if(str[i] != ' ')
//             sparse[sparseLen++] = str[i];
//     } return sparse;
// }
// 
// string arrayToStr(int* arr) {
//     string result;
//     int arrSize = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i < arrSize; i++) {
//         result += arr[i] + " ";
//     } return result.substr(0, result.size()-1);
// }


/**
 * Outputs a given int array as a oneline string
 * @param arr Given int array, in theory represents a sparse matrix
 */
void outputMatrix(int arr[]) {
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    string output;

    for(int i=0; i < arrSize; i++) {
        output += arr[i] + " ";
    } cout << output.substr(0, arrSize-1) << endl;
}

/**
 * Copies a given int array.
 * @param arr Given int array to be copied
 * @return the pointer to the copy of the given int array
 */
int *copyIntArray(int arr[]) {
    static int cpy[sizeof(arr)/sizeof(arr[0])];
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i < arrSize; i++) {
        cpy[i] = arr[i];
    } return cpy;
}

/**
 * Populates a given array with the contents of a given string.
 * @param str Given string to be put into array
 * @param arr Given array to be populated with the string (removes spaces)
 */
void populateArray(string str, int arr[]) {
    int xLen = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            x[xLen++] = str[i];
    }
}

/**
 * Transposes a given array.
 * Outputs transposition in efficient representation.
 * @param arr Given array to be transposed. Assumes efficient representation
 */
void transpose(int arr[]) {
    int *tmp = copyIntArray(arr);

    for(int i=0; i < xSize; i+3) {  // iterates every row-column-value group
        arr[i] = arr[i+1];
        arr[i+1] = tmp[i];      // swaps the rows and columns as per transposition
    }
    
    for(int i=0; i < xSize; i+3) {    // bubble sort by row-column-value trios
        tmp = arr;
        for(int j=i+3; j < xSize; j+3) {
            if(arr[j] < arr[i] || arr[j+1] < arr[i+1]) {       // if rows OR columns are in wrong order
                arr[i] = arr[j];
                arr[i+1] = arr[j+1];
                arr[i+2] = arr[j+2];

                arr[j] = tmp[j];
                arr[j+1] = tmp[j+1];
                arr[j+2] = tmp[j+2];
            }
        }
    }
    
    outputMatrix(arr);
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