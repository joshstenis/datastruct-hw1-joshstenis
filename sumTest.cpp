#include <iostream>
using namespace std;

int x[12];
int y[12];
int xSize, ySize = 12;

void outputMatrix(int arr[]) {
    int size = sizeof(arr)/sizeof(arr[0]);
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

void copyToArray(int src[], int dest[]) {
    int srcSize = sizeof(src)/sizeof(src[0]);
    int destSize = sizeof(dest)/ sizeof(dest[0]);

    for(int i=0; i < srcSize; i++) {
        if(i >= destSize) {break;}
        dest[i] = src[i];
    }
}

void sum(int x[], int y[]) {
    int sum[60];
    int sumSize = 60;
    int sharedVals = 0;

    copyToArray(x, sum);        // Populates sum[] with x[]
    int nextEmpty = 30;

    for(int i=0; i < sumSize; i+=3) {             // Populates sum[] with y[], also checks how many values on in same location X and Y have
        for(int j=0; j < ySize; j++) {
            if(sum[i] == y[j] && sum[i+1] == y[j+1])
                sum[i+2] += y[j+2];
            else {
                sum[nextEmpty] = y[j];
                sum[nextEmpty+1] = y[j+1];
                sum[nextEmpty+2] = y[j+2];
                nextEmpty += 3;
            }
        }
    }

    int perfectSum[nextEmpty];      //perfect sized array for the sum of X and Y
    copyToArray(sum, perfectSum);
    cout << perfectSum[3] << endl;

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
    } outputMatrix(perfectSum);
}

int main() {
    cout << "MAIN BEGINS" << endl;
    string rawX = "0 0 1 0 1 3 2 2 7 4 2 8";       // Test X string
    string rawY = "0 1 4 1 5 4 2 3 4 2 4 7";       // Test Y string
    // getline(cin, rawMatrix);

    populateArray(rawX, x);
    outputMatrix(x);
    populateArray(rawY, y);
    outputMatrix(y);

    cout << "ARRAY POPULATED -- " << endl;
    sum(x, y);
    cout << "ARRAYS ADDED" << endl;
}