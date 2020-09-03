#include <iostream>
using namespace std;

// string removeSpaces(string str) {
//     char input[str.length()];
//     int inputSize = sizeof(input)/sizeof(input[0]);

//     for(int i=0; i < str.length(); i++) {
//         input[i] = str[i];
//     } for(int i=0; i < inputSize; i++) {
//         if(input[i] != ' ') {
//             sparse.push_back(input[i]);
//         }
//     }
// }

int *strToArray(string str) {           // CONFIRMED FUNCTIONAL
    static int sparse[5];
    int sparseLen = 0;
    for(int i=0; i < str.length(); i++) {
        if(str[i] != ' ')
            sparse[sparseLen++] = str[i];
    } return sparse;
    
    // string noSpace = removeSpaces(str);
    // cout << str << endl;
    // for(int i=0; i < str.length(); i++) {
    //     sparse[i] = str[i];
    // } return sparse;
}


int main() {
    string str;
    int expected[] = {1, 2, 3, 4, 5};
    int expectedSize = 5;
    bool result = true;

    cout << "Please enter your string: ";
    getline(cin, str);
    cout << endl;

    int *actual;
    actual = strToArray(str);
    for(int i=0; i < 5; i++) {
        cout << *(actual+i) << endl;        // Output method NOT confirmed functional
    }

    return 0;

    // for(int i=0; i < expectedSize; i++) {       //compare actual to expected
    //     if(actual[i] != expected[i]) {
    //         result = false;
    //         break;
    //     }
    // }
    // cout << boolalpha << "Result: " << result << endl;
}