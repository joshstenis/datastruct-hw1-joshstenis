#include <iostream>
using namespace std;

int x[6];
int xSize = 6;
int ySize = 6;
int y[6];

void outputMatrix(int arr[], int size) {
    cout << arr[0];
    for(int i=1; i < size; i++) {
        cout << " " << arr[i];
    } cout << endl;
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
        for(int j=0; j < ySize; j+=3) {
            if(x[i] == y[j+1]) {
                product[nextEmpty++] = x[i+1];
                product[nextEmpty++] = y[j];
                product[nextEmpty++] = x[i+2] * y[j+2];
                cout << x[i+2] * y[j+2] << " NE: " << nextEmpty << endl;
            }
        }
    }
    cout << "PRODUCT MATRIX" << endl;
    outputMatrix(product, 12);
}

int main() {
    string rawX = "0 0 1 0 1 3";        // Test X string
    string rawY = "0 0 3 1 0 2";        // Test Y string

    populateArray(rawX, x);
    outputMatrix(x, xSize);
    populateArray(rawY, y);
    outputMatrix(y, ySize);

    multiply(x, xSize, y, ySize);
}