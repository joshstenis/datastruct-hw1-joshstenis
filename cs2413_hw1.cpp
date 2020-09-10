#include <iostream>
using namespace std;

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
 * Copies the src array into the dest array. Usually used for trimming extraneous elements at the end of src[]
 * @param src Array to be copied into dest
 * @param srcSize Size of src
 * @param dest Copy array of src
 * @param destSize Size of dest
 */
void copyToArray(int src[], int srcSize, int dest[], int destSize) {
    for(int i=0; i < destSize; i++)
        dest[i] = src[i];
}

/**
 * Sorts a matrix in row-column-value trios
 * @param arr The array to be sorted
 * @param size The size of arr[]
 */
void sortMatrix(int arr[], int size) {
    for(int i=0; i < size; i+=3) {
        for(int j=i+3; j < size; j+=3) {
            if(arr[j] < arr[i] || (arr[j] == arr[i] && arr[j+1] < arr[i+1])) {
                arr[i] = (arr[i] ^ arr[j]) ^ (arr[j] = arr[i]);
                arr[i+1] = (arr[i+1] ^ arr[j+1]) ^ (arr[j+1] = arr[i+1]);
                arr[i+2] = (arr[i+2] ^ arr[j+2]) ^ (arr[j+2] = arr[i+2]);
            }
        }
    }
}

/**
 * Outputs a given int array as a oneline string
 * @param arr Given int array, in theory represents a sparse matrix
 * @param size Size of given array
 */
void outputMatrix(int arr[], int size) {
    string str = "" + arr[0];
    for(int i=1; i < size; i++)
        str += " " + arr[i];
    if(str[str.length()-1] == ' ')                  // If trailing space, remove trailing space
        cout << str.substr(0, str.length()-2);
    else
        cout << str;
}

/**
 * Exponent function since we can't use any math libraries -_-
 * @param base The base of the exponent expression
 * @param power The exponent
 */
int power(int base, int power) {
    int output = base;
    for(int i=0; i < power-1; i++)
        output *= base;
    if(power == 0) return 1;
    return output;
}

/**
 * Converts a string number into an integer -- (ex. "-140" == -140)
 * @param str The string number
 */
int strToInt(string str) {
    int val = 0;
    for(int i=0 ;i < str.length(); i++) {
        if(str[i] != '-')
            val += power(10, str.length()-i) * (str[i] - 48);
    } if(str[0] == '-') val *= -1;
    
    return val/10;
}

/**
 * Populates a given array with the numerous inputs of amount e
 * @param e Number of elements in given matrix
 * @param arr Given array to be populated with the inputs (delimited by whitespace)
 */
void populateArray(int e, int arr[]) {
    string num;
    for(int i=0; i < e; i++) {
        cin >> num;
        arr[i] = strToInt(num);
    } cin.ignore(1, ' ');
}

/**
 * Transposes a given array.
 * Outputs transposition in efficient representation.
 * @param arr Given array to be transposed. Assumes efficient representation
 * @param size Size of given array
 */
void transpose(int arr[], int size) {
    int j = 0;
    for(int i=0; i < size; i+=3)  // swaps row and column values for each trio
        arr[i] = (arr[i] ^ arr[i+1]) ^ (arr[i+1] = arr[i]);

    sortMatrix(arr, size);
}

/**
 * Multiplies two matrices -- Assumes efficient representation
 * @param x First matrix to multiply
 * @param xSize The size of x
 */
void multiply(int x[], int xSize) {
    int size = xSize * xSize;
    int product[size] = {0};
    int nextEmpty = 0;
    int sum = 0;
    bool val = false;
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {

            for(int k=0; k < xSize; k+=3) {
                for(int l=0; l < ySize; l+=3) {
                    if(x[k+1] == y[l] && x[k] == i && y[l+1] == j) {
                        sum += x[k+2] * y[l+2];
                        val = true;
                    }
                }
            } if(val) {
                product[nextEmpty++] = i;
                product[nextEmpty++] = j;
                product[nextEmpty++] = sum;
                sum = 0;
                val = false;
            }
        }
    }
    
    int pSize = nextEmpty;
    int pProduct[pSize] = {0};
    copyToArray(product, size, pProduct, pSize);
    
    sortMatrix(pProduct, pSize);
    outputMatrix(pProduct, pSize);
}

/**
 * Calculates the sum of two matrices.
 * @param x Given array to be added to Y (static)
 * @param xSize Size of x
 */
void sum(int x[], int xSize) {
    int sum[xSize*2] = {0};
    int sumSize = xSize*2;

    int nextEmpty = 0;
    for(int i=0; i < xSize; i+=3) {       // Put X and Y shared points into sum[]
        for(int j=0; j < ySize; j+=3) {
            if(x[i] == y[j] && x[i+1] == y[j+1]) {
                sum[nextEmpty++] = x[i];
                sum[nextEmpty++] = x[i+1];
                sum[nextEmpty++] = x[i+2] + y[j+2];
            }
        }
    }
    
    for(int i=0; i < xSize; i+=3) {
        bool inX = false;
        bool inY = false;
        for(int j=0; j < nextEmpty; j+=3) {
            if(sum[j] == x[i] && sum[j+1] == x[i+1]) inX = true;
            if(sum[j] == y[i] && sum[j+1] == y[i+1]) inY = true;
        }
        
        if(!inY) {
            sum[nextEmpty++] = y[i];
            sum[nextEmpty++] = y[i+1];
            sum[nextEmpty++] = y[i+2];
        } if(!inX) {
            sum[nextEmpty++] = x[i];
            sum[nextEmpty++] = x[i+1];
            sum[nextEmpty++] = x[i+2];
        }
    }
    
    int pSize = nextEmpty;
    int pSum[pSize];
    copyToArray(sum, sumSize, pSum, pSize);

    sortMatrix(pSum, pSize);
    outputMatrix(pSum, pSize);          // nextEmpty reflects the size of sum
}

int main() {
    char task;
    string elem;

    cin >> task;
    cin >> elem;
    int e = strToInt(elem) * 3;

    int x[e] = {0};
    int xSize = e;
    
    cin.ignore(1, '\n');
    if(task == '1') {           // Task 1
        populateArray(e, x);
        transpose(x, xSize);
        outputMatrix(x, xSize);
    } else if(task == '2') {            // Task 2
        populateArray(e, x);
        sum(x, xSize);
    } else if(task == '3') {            // Task 3
        populateArray(e, x);
        transpose(x, xSize);
        multiply(x, xSize);
    } return 0;
}