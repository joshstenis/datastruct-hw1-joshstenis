#include <iostream>
using namespace std;

int x[30];
int xSize = sizeof(x)/sizeof(x[0]);

void outputMatrix(int arr[]) {
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    string output;

    for(int i=0; i < arrSize; i++) {
        output += arr[i] + " ";
    } cout << output.substr(0, arrSize-1) << endl;
}

void populateArray(string str, int arr[]) {
    int xLen = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            x[xLen++] = str[i];
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

    for(int i=0; i < xSize; i+3) {  // iterates every row-column-value group
        arr[i] = arr[i+1];
        arr[i+1] = tmp[i];      // swaps the rows and columns as per transposition
    }
    cout << "ROW AND COLUMN VALUES SWAPPED" << endl;

    for(int i=0; i < xSize; i+3) {    // bubble sort by row-column-value trios
        tmp = arr;
        for(int j=i+3; j < xSize; j+3) {
            if(arr[j] < arr[i] || (arr[j] == arr[i] && arr[j+1] < arr[i+1])) {       // if rows OR columns are in wrong order
                arr[i] = arr[j];
                arr[i+1] = arr[j+1];
                arr[i+2] = arr[j+2];

                arr[j] = tmp[j];
                arr[j+1] = tmp[j+1];
                arr[j+2] = tmp[j+2];
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

    populateArray(rawMatrix, x);
    cout << "ARRAY POPULATED" << endl;
    transpose(x);
    cout << "ARRAY TRANSPOSED" << endl;
}