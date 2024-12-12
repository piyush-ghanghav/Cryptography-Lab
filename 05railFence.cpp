#include <iostream>
#include <string>

using namespace std;
string encrypt(string& plaintext, int rails) {
    string ciphertext;
    int len = plaintext.length();
    int railSize = len / rails;

    for (int i = 0; i < rails; i++) {
        for (int j = i; j < len; j += railSize) {
            ciphertext += plaintext[j];
        }
    }

    return ciphertext;
}

string decrypt(string& ciphertext, int rails) {
    string plaintext;
    int len = ciphertext.length();
    int railSize = len / rails;

    for (int i = 0; i < railSize; i++) {
        for (int j = i; j < len; j += railSize) {
            plaintext += ciphertext[j];
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    cout<<"Enter the plain text: ";
    cin>>plaintext;

    int rails = 3;

    string ciphertext = encrypt(plaintext, rails);
    cout<< "Ciphertext: " << ciphertext <<  endl;
    
    string decryptedtext = decrypt(ciphertext, rails);
    cout<< "Plaintext after decryption: " << plaintext <<  endl;

    return 0;
}