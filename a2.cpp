#include <iostream>
#include <string>
using namespace std;

class PolyalphabeticCipher {
    public:
        int n = 26;

        char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        int findIndex(char c) {
            for (int i = 0; i < n; i++) {
                if (alpha[i] == c) {
                    return i;
                }
            }
            return -1;
        }

       
        string Encrypt(const string& text, const string& keyword) {
            string result = "";

            string extendedKeyword = "";

            int keywordLength = keyword.length();
            for (int i = 0; i < text.length(); i++) {
                if (isalpha(text[i])) { 
                    extendedKeyword += keyword[i % keywordLength];
                } else {
                    extendedKeyword += text[i]; 
                }
            }
            for (int i = 0; i < text.length(); i++) {
                char c = text[i];
                if (isalpha(c)) { 
                    bool isLower = islower(c);
                    c = toupper(c);
                    char k = toupper(extendedKeyword[i]);
                    int index = findIndex(c);
                    int keyIndex = findIndex(k);
                    if (index != -1 && keyIndex != -1) {
                        int newIndex = (index + keyIndex) % n;
                        char newChar = alpha[newIndex];
                        result += isLower ? tolower(newChar) : newChar;
                    }
                } else {
                    result += c; // non-alphabetic characters remain unchanged
                }
            }

            return result;
        }

        string Decrypt(const string& text, const string& keyword) {
            string result = "";
                  string extendedKeyword = "";

            int keywordLength = keyword.length();
            for (int i = 0; i < text.length(); i++) {
                if (isalpha(text[i])) { 
                    extendedKeyword += keyword[i % keywordLength];
                } else {
                    extendedKeyword += text[i]; 
                }
            }
            for (int i = 0; i < text.length(); i++) {
                char c = text[i];
                if (isalpha(c)) { 
                    bool isLower = islower(c);
                    c = toupper(c);
                    char k = toupper(extendedKeyword[i]);
                    int index = findIndex(c);
                    int keyIndex = findIndex(k);
                    if (index != -1 && keyIndex != -1) {
                        int newIndex = (index - keyIndex + n) % n;
                        char newChar = alpha[newIndex];
                        result += isLower ? tolower(newChar) : newChar;
                    }
                } else {
                    result += c; // non-alphabetic characters remain unchanged
                }
            }

            return result;
        }
};

int main() {
    PolyalphabeticCipher obj;

    string text;
    string keyword;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the keyword: ";
    cin >> keyword;

    string encryptedText = obj.Encrypt(text, keyword);
    cout << "\nEncrypted Text: " << encryptedText << endl;

    string decryptedText = obj.Decrypt(encryptedText, keyword);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
