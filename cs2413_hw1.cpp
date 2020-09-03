#include <iostream>
using namespace std;

int x[30];
int xSize = sizeof(x)/sizeof(x[0]);
int y[30];
int ySize = sizeof(y)/sizeof(y[0]);
int z1[30];
int z1Size = sizeof(z1)/sizeof(z1[0]);
int z2[60];
int z2Size = sizeof(z2)/sizeof(z2[0]);
int z3[64];
int z3Size = sizeof(z3)/sizeof(z3[0]);

int *strToArray(string str) {
    static int sparse[30];
    int sparseLen = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            sparse[sparseLen++] = str[i];
    } return sparse;
}

string arrayToStr(int* arr) {
    string result;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i < arrSize; i++) {
        result += arr[i] + " ";
    } return result.substr(0, result.size()-1);
}

void multiply() {
    int result[30];
}

void transpose() {
    int result[40];
    for(int i=0; i < xSize; i+3) {        // iterates every row-column-value group -- ASSUMES EFFICIENT REP. -- ALSO ASSUMES I CAN RETURN IN EFFICIENT REP.
        result[i] = x[i+1];
        result[i+1] = x[i];
    }
}

void sum() {
    // int result[40];
    // for(int i=0; i < ; i++) {
        
    // }
}

int main() {
    string rawMatrix;
    getline(cin, rawMatrix);
    int* matrix = strToArray(rawMatrix);
    // cout << multiply();
}