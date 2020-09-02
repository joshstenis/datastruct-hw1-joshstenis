#include <iostream>
using namespace std;

class Matrix {
    int[] values;
    public:
        Matrix(int*);
        int* product(int* arr);
        int* transpose();
        int* sum(int* arr);
};

Matrix::Matrix(int* vals) {
    values = vals;
}

int main() {
    return 0;
}