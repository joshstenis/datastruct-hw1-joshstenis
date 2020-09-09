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
    int elementProduct;

    for(int i=0; i < xSize; i+=3) {
        for(int j=0; j < ySize; j+=3) {
            elementProduct = 0;
            if(x[i] == y[j+1]) {
                product[nextEmpty++] = x[i+1];
                product[nextEmpty++] = y[j];
                elementProduct = x[i+2] * y[j+2];
                
                for(int k=0; k < xSize; k+=3) {
                    for(int l=0; l < ySize; l+=3) {
                        if(x[k] == x[i] && y[j+1] == y[l+1] && x[k+1] == x[i+1]+1 && y[l] == y[j]+1)
                            elementProduct += x[k+2] * y[l+2];
                    }
                } product[nextEmpty++] = elementProduct;

            }
        }
    }
    cout << "PRODUCT MATRIX" << endl;
    outputMatrix(product, 12);
}

int main() {
    string rawX = "0 0 1 0 1 3";        // Test X string
    string rawY = "0 0 3 0 1 2";        // Test Y string

    populateArray(rawX, x);
    outputMatrix(x, xSize);
    populateArray(rawY, y);
    outputMatrix(y, ySize);

    multiply(x, xSize, y, ySize);
}