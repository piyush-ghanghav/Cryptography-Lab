#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class HillCipher {
    public:
        char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        int n = 26;

        int findIndex(char c) {
            for (int i = 0; i < n; i++) {
                if (alpha[i] == toupper(c)) {
                    return i;
                }
            }
            return -1;
        }

        string Encrypt(const string& plain, int key[2][2]) {
            int length = plain.length();
            int number[2], cipher[2];
            char ciphertext[3]; // Holds the encrypted pair
            string finalCiphertext = ""; // Combined encrypted text

            cout << "\n-------------------Encrypting two-character pairs-----------------------\n";

            for (int w = 0; w < length; w += 2) {
                for (int i = 0; i < 2; i++) {
                    number[i] = findIndex(plain[w + i]);
                }

                for (int i = 0; i < 2; i++) {
                    cipher[i] = 0;
                    for (int j = 0; j < 2; j++) {
                        cipher[i] += key[i][j] * number[j];
                    }
                    cipher[i] %= 26;
                    ciphertext[i] = alpha[cipher[i]];
                }

                cout << "\nCiphertext for pair: " << ciphertext[0] << ciphertext[1] << endl;

                finalCiphertext += ciphertext[0];
                finalCiphertext += ciphertext[1];
            }

            return finalCiphertext;
        }
};

int main() {
    HillCipher obj;

    string plainText;
    

    int key[2][2] = {
        {7, 8},  // 'H' = 7, 'I' = 8
        {11, 11} // 'L' = 11, 'L' = 11
    };

    cout << "Enter the plain text (even number of characters): ";
    cin >> plainText;

    string Ciphertext = obj.Encrypt(plainText, key);

    cout << "\nFinal Combined Ciphertext: " << Ciphertext << endl;

    return 0;
}
