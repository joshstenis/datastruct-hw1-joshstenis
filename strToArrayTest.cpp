#include <iostream>
using namespace std;

int *strToArray(string str) {
    static int sparse[5];
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ') {
            cout << str[i] << endl;
            sparse[i] = str[i];
        }
    } return sparse;
}

int main() {
    string str;
    int expected[] = {1, 2, 3, 4, 5};
    int expectedSize = 5;
    bool result = true;

    cout << "Please enter your string: ";
    cin >> str;
    cout << endl;

    int *actual;
    actual = strToArray(str);
    // for(int i=0; i < 5; i++) {
    //     cout << *(actual+i) << endl;
    // }


    // for(int i=0; i < expectedSize; i++) {       //compare actual to expected
    //     if(actual[i] != expected[i]) {
    //         result = false;
    //         break;
    //     }
    // }
    // cout << boolalpha << "Result: " << result << endl;
}