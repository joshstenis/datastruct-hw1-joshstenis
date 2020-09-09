#include <iostream>
using namespace std;

int x[30];              // Input from file
int xSize = sizeof(x)/sizeof(x[0]);

int y[] = { 0, 0, 1,               // Given as part of Assignment 1
            0, 3, 9,
            0 ,5, 5,
            1, 4, 2,
            1, 7, 3,
            2, 1, 4,
            2, 6, 8,
            3, 2, 2,
            4, 0, 1,
            4, 4, 7 };
int ySize = sizeof(y)/sizeof(y[0]);

/**
 * Shifts all elements of the given int array to the left by given amount shift, starting at given idx
 * @param arr Given int array
 * @param idx The starting index in given array
 * @param size The size of given array
 * @param shift The number of spaces each element will be moved
 */
void leftShift(int arr[], int idx, int size, int shift) {
	for(int i=idx; i < size; i++)
		arr[i] = arr[i+shift];
}

/**
 * Copies the src array into the dest array. Usually used for trimming extraneous elements at the end of src[]
 * @param src Array to be copied into dest
 * @param srcSize Size of src
 * @param dest Copy array of src
 * @param destSize Size of dest
 */
void copyToArray(int src[], int srcSize, int dest[], int destSize) {
    for(int i=0; i < destSize; i++) {
        dest[i] = src[i];
    }
}

/**
 * Outputs a given int array as a oneline string
 * @param arr Given int array, in theory represents a sparse matrix
 */
void outputMatrix(int arr[], int size) {
    cout << arr[0];
    for(int i=1; i < size; i++) {
        cout << " " << arr[i];
    } cout << endl;
}

/**
 * Populates a given array with the contents of a given string.
 * @param str Given string to be put into array
 * @param arr Given array to be populated with the string (removes spaces)
 */
void populateArray(string str, int arr[]) {
    int j = 0;
    int tmp;
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
    int j = 0;
    for(int i=0; i < xSize; i+=3) {  // swaps row and column values for each trio
        arr[i] = (arr[i] ^ arr[i+1]) ^ (arr[i+1] = arr[i]);
    }

    int *tmp;
    for(int i=0; i < xSize; i+=3) {    // bubble sort by row-column-value trios
        for(int j=i+3; j < xSize; j+=3) {
            if(arr[j] < arr[i] || (arr[j] == arr[i] && arr[j+1] < arr[i+1])) {       // if rows OR columns are in wrong order
                arr[i] = (arr[i] ^ arr[j]) ^ (arr[j] = arr[i]);
                arr[i+1] = (arr[i+1] ^ arr[j+1]) ^ (arr[j+1] = arr[i+1]);
                arr[i+2] = (arr[i+2] ^ arr[j+2]) ^ (arr[j+2] = arr[i+2]);
            }
        }
    } outputMatrix(arr, xSize);
}

/**
 * Multiplies two matrices -- Assumes efficient representation
 * @param x First matrix to multiply
 * @param xSize The size of x
 * @param y Second matrix to multiply
 * @param ySize The size of y
 */
void multiply(int x[], int xSize, int y[], int ySize) {
    int product[30];
    int nextEmpty = 0;

    for(int i=0; i < xSize; i+=3) {
        for(int j=0; j < ySize; j+=3) {
            if(x[i] == y[j+1]) {
                product[nextEmpty++] = x[i+1];
                product[nextEmpty++] = y[j];
                product[nextEmpty++] = x[i+2] * y[j+2];
                cout << x[i+2] * y[j+2] << " NE: " << nextEmpty << endl;
            }
        }
    }
    outputMatrix(product, 30);
}

/**
 * Calculates the sum of two matrices.
 */
void sum(int x[], int xSize, int y[], int ySize) {
    int sum[60];
    int sumSize = 60;
    for(int i=0; i < 60; i++)       // Clear sum
        sum[i] = 0;

    for(int i=0; i < (xSize+ySize); i++) {       // Put X and Y into sum[]
        if(i < xSize)
            sum[i] = x[i];
        else
            sum[i] = y[i-xSize];
    } outputMatrix(sum, sumSize);
    
    int sharedVals = 0;
    for(int i=0; i < xSize; i+=3) {
        for(int j=ySize; j < sumSize; j+=3) {
            if(sum[i] == sum[j] && sum[i+1] == sum[j+1]) {      // Duplicate trio
                sum[i+2] += sum[j+2];

                sum[j] = -1;
                sum[j+1] = -1;
                sum[j+2] = -1;
            }
        }
    }
    
    for(int i=xSize; i < sumSize; i+=3) {       // Shifts values after each duplicate
        if(sum[i] == -1) {
            leftShift(sum, i, sumSize, 3);
        }
    }
    
    int perfectSize = -1;
    for(int i=xSize; i < sumSize; i+=3) {       // Shifts values after each duplicate
        if(sum[i] == -1) {
            cout << "P SIZE " << i << endl;
            if(perfectSize < 0) {
                perfectSize = i;
                break;
            }
        }
    }

    int perfectSum[perfectSize];
    copyToArray(sum, sumSize, perfectSum, perfectSize);

    int *tmp;
    for(int i=0; i < xSize; i+=3) {    // bubble sort by row-column-value trios
        for(int j=i+3; j < xSize; j+=3) {
            tmp = &perfectSum[j];
            if(perfectSum[j] < perfectSum[i] || (perfectSum[j] == perfectSum[i] && perfectSum[j+1] < perfectSum[i+1])) {       // if rows OR columns are in wrong order
                perfectSum[i] = perfectSum[j];
                perfectSum[i+1] = perfectSum[j+1];
                perfectSum[i+2] = perfectSum[j+2];

                perfectSum[j] = *tmp++;
                perfectSum[j+1] = *tmp++;
                perfectSum[j+2] = *tmp++;
            }
        }
    } cout << "ARRAY BUBBLE SORTED" << endl;
    outputMatrix(perfectSum, perfectSize);          // nextEmpty reflects the size of sum
}

int main() {
    string task;
    string rawMatrix;
    getline(cin, task);
    cout << "TASK INPUT" << endl;

    if(task == "1") {           // Task 1
        string rawMatrix;
        getline(cin, rawMatrix);
        populateArray(rawMatrix, x);
        transpose(x);
    } else if(task == "2") {            // Task 2
        getline(cin, rawMatrix);
        populateArray(rawMatrix, y);
        sum(x, xSize, y, ySize);
    } else if(task == "3") {            // Task 3
        getline(cin, rawMatrix);
        populateArray(rawMatrix, x);
        multiply(x, xSize, y, ySize);
    } return 0;
}