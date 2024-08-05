#include <iostream>
#include <string>
using namespace std;

class CaesarCipher{
    public:
        int n = 26;

        // Array of Alphabets
        char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        // function to return alphabet index
        int findIndex(char c) {
            for (int i = 0; i < n; i++) {
                if (alpha[i] == c) {
                    return i;
                }
            }
            return -1; 
        }

        string Encrypt(const string& text, int key) {
            string result = "";

            for (char c : text) {
                if (isalpha(c)) { 
                    bool isLower = islower(c);      // flag => is lowercase? => used while Encryption
                    c = toupper(c); 
                    int index = findIndex(c);
                    if (index != -1) {
                        int newIndex = (index + key) % n;       // setting newIndex by shifting upto Key length in array
                        char newChar = alpha[newIndex];
                        result += isLower ? tolower(newChar) : newChar;
                    }
                } else {
                    result += c;        // character !alphabet => directly add in result
                }
            }

            return result;
        }

        string Decrypt(const string& text, int key) {
            return Encrypt(text, n - key);                  // Decrypt is encrypt with `n-key`  => 26-3 = 23 => setting key as 23  
        }
};

int main() {

    CaesarCipher obj;


    string text = "HELLO";
    int key = 3;

    // cout << "Enter the text: ";
    // getline(cin, text);
    // cout << "Enter the key: ";
    // cin >> key;

    string encryptedText = obj.Encrypt(text, key);
    cout << "\nEncrypted Text: " << encryptedText << endl;

    string decryptedText = obj.Decrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
