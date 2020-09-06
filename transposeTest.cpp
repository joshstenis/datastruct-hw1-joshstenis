#include <iostream>
using namespace std;

int x[30];
int xSize = sizeof(x)/sizeof(x[0]);
int *zOne;      // same size as x

/**
 * Prints the contents of
 */
void outputMatrix(int arr[]) {
    cout << x[0];
    for(int i=1; i < xSize; i++) {
        cout << " " << x[i];
    } cout << endl;
}

void populateArray(string str, int arr[]) {
    int j = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            arr[j++] = str[i];
    }
}

int *copyIntArray(int arr[]) {
    static int cpy[sizeof(arr)/sizeof(arr[0])];
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i < arrSize; i++) {
        cpy[i] = arr[i];
    } return cpy;
}

///////////////
void transpose(int arr[]) {
    int *tmp = copyIntArray(arr);
    cout << "ARRAY COPIED -- " << xSize << endl;

    int j = 0;
    for(int i=0; i < xSize; i+=3) {  // swaps row and column values for each trio
        cout << "ITER " << j++ << endl;
        arr[i] = (arr[i] ^ arr[i+1]) ^ (arr[i+1] = arr[i]);
    }
    cout << "ROW AND COLUMN VALUES SWAPPED" << endl;

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
    } cout << "ARRAY BUBBLE SORTED" << endl;
    
    outputMatrix(arr);
}
////////////////

int main() {
    cout << "MAIN BEGINS" << endl;
    string rawMatrix = "0 0 1 0 1 3 2 2 7 4 2 8";       // Test string
    // getline(cin, rawMatrix);

    cout << x[4] << endl;
    populateArray(rawMatrix, x);
    cout << "ARRAY POPULATED -- " << x[4] << endl;
    transpose(x);
    cout << "ARRAY TRANSPOSED" << endl;
}