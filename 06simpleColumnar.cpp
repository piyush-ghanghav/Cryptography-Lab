#include <iostream>
#include <vector>
#include <string>

using namespace std;

void simpleColumnar(string& plaintext, int columns) {
    
    int rows = (plaintext.length() + columns - 1) / columns;
     vector< string> matrix(rows,string(columns,' '));

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (index < plaintext.length()) {
                matrix[i][j] = plaintext[index++];
            }
        }
    }

     cout << "Ciphertext: ";
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
             cout << matrix[i][j];
        }
    }
     cout <<  endl;
}

void decryptSimpleColumnar(const string& ciphertext, int columns) {
    int rows = (ciphertext.length() + columns - 1) / columns;
    vector<string> matrix(rows, string(columns, ' '));

    int index = 0;
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (index < ciphertext.length()) {
                matrix[i][j] = ciphertext[index++];
            }
        }
    }

    cout << "Decrypted plaintext: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] != ' ') { 
                cout << matrix[i][j];
            }
        }
    }
    cout << endl;
}
int main() {
    string plaintext;
    cout<<"Enter plaintext: ";
    cin>>plaintext;
    int columns = 5;
    simpleColumnar(plaintext, columns);

    string ciphertext;
    cout << "Enter ciphertext to decrypt: ";
    cin >> ciphertext;
    decryptSimpleColumnar(ciphertext, columns);

    return 0;
}