#include <iostream>
using namespace std;

// class Matrix {
//     int* values;
//     public:
//         Matrix(int* vals) {
//             this->values = vals;
//         } int* multiply(int* arr) {
//             
//         } int* transpose() {
//             return 0;
//         } int* sum(int* arr) {

//         }
// };

int* strToArray(string str) {
    int sparse[30];
    for(int i=0; i < str.length(); i++) {
        if(str[i] == ' ') {continue;}
        else {
            sparse[i] = str[i];
        }
    }
}

string arrayToStr(int* arr) {
    string result;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i < arrSize; i++) {
        result += arr[i] + " ";
    } return result.substr(0, result.size()-1);
}

int* multiply(int*, int*) {
    int result[30];
}

int* transpose(int* arr) {
    int result[40];
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i < arrSize; i+3) {        // iterates every row-column-value group -- ASSUMES EFFICIENT REP. -- ALSO ASSUMES I CAN RETURN IN EFFICIENT REP.
        result[i] = arr[i+1];
        result[i+1] = arr[i];
    } return result;
}

int* sum(int* arr1, int* arr2) {
    int result[40];
    for(int i=0; i < sizeof(arr1); i++) {
        
    }
}

int main() {
    string rawMatrix;
    cin >> rawMatrix;
    int* matrix = strToArray(rawMatrix);
    // cout << multiply();
}