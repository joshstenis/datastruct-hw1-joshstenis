#include <iostream>
using namespace std;

int x[12];
int y[12];
int xSize = 12;
int ySize = 12;

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
            arr[j++] = str[i] - 48;        // Method was using unicode values, so the constant 48 was found to gain the desired value
    }
}

void copyToArray(int src[], int srcSize, int dest[], int destSize) {
    for(int i=0; i < destSize; i++) {
        dest[i] = src[i];
    }
}

void leftShift(int arr[], int idx, int size, int shift) {
	for(int i=idx; i < size; i++)
		arr[i] = arr[i+shift];
}

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
    } outputMatrix(sum, 24);
    
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
    cout << "MAIN BEGINS" << endl;
    string rawX = "0 0 1 0 1 3 2 2 7 4 2 8";       // Test X string
    string rawY = "0 0 4 1 5 4 2 3 4 2 4 7";       // Test Y string
    // getline(cin, rawMatrix);

    populateArray(rawX, x);
    outputMatrix(x, xSize);
    populateArray(rawY, y);
    outputMatrix(y, ySize);

    cout << "ARRAY POPULATED -- " << endl;
    sum(x, xSize, y, ySize);
    cout << "ARRAYS ADDED" << endl;
}