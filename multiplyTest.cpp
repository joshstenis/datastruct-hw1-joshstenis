#include <iostream>
using namespace std;

int x[12];
int xSize = 12;
int ySize = 12;
int y[12];

void outputMatrix(int arr[], int size) {
    cout << arr[0];
    for(int i=1; i < size; i++) {
        cout << " " << arr[i];
    } cout << endl;
}

void copyToArray(int src[], int dest[]) {
    int srcSize = sizeof(src)/sizeof(src[0]);
    int destSize = sizeof(dest)/sizeof(dest[0]);

    for(int i=0; i < srcSize; i++) {
        if(i >= destSize) {break;}
        dest[i] = src[i];
    }
}

void populateArray(string str, int arr[]) {
    int j = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            arr[j++] = str[i] - 48;
    }
}

void multiply(int x[], int xSize, int y[], int ySize) {
    int product[12];
    int nextEmpty = 0;

    for(int i=0; i < xSize; i+=3) {
        for(int j=i; j < ySize; j+=3) {
            if(x[i+1] == y[j+1]) {cout << "column " << x[i+1] << endl;}
            if(x[i] == y[j]) {
                cout << "row " << x[i] << endl;
                // product[nextEmpty++] = y[j];
                // product[nextEmpty++] = y[j+1];
                // product[nextEmpty++] = x[i+2] * y[j+2];
            }
        }
    } int p[nextEmpty];

    copyToArray(product, p);
    outputMatrix(p, 12);
}

int main() {
    string rawX = "0 0 1 0 1 3 2 2 7 4 2 8";        // Test X string
    string rawY = "0 0 3 1 0 3 2 4 8 4 2 7";        // Test Y string

    populateArray(rawX, x);
    outputMatrix(x, xSize);
    populateArray(rawY, y);
    outputMatrix(y, ySize);

    multiply(x, xSize, y, ySize);
}