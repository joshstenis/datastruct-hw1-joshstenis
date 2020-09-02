#include <iostream>
using namespace std;

class Matrix {
    int values[][];
    public:
        Matrix(int* vals) {
            this->values = vals;
        } int* multiply(int* arr) {
            int product[sizeof(this->values)][sizeof(arr[0])];
            for(int i=0; i < sizeof(this->values); i++) {
                for(int j=0; j < sizeof(this->values[i]); j++) {
                    product[i][j] = this->values[i][j] * arr[i][j];
                }
            }
        } int* transpose() {
            return 0;
        } int* sum(int* arr) {

        }
};

int main() {
    return 0;
}