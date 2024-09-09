#include<bits/stdc++.h>

using namespace std;

class PlayfairCipher{
    public:

    void generateMatrix(string &key, vector<vector<char>>& matrix, unordered_map<char, pair<int,int>> &position){

        string alpha = "abcdefghiklmnopqrstuvwxyz";         // without j
        string keyMatrix = key;
        
        for(char c: alpha){
                if(keyMatrix.find(c) == string::npos){
                    keyMatrix += c;
                }

        }
        // cout<<keyMatrix;

        int k = 0;

        for(int i =0; i<5; ++i){
            for(int j =0; j<5; ++j){
                matrix[i][j] = keyMatrix[k];
                position[keyMatrix[k]] = make_pair(i,j);
                ++k; 
            }
        }

    }
    string formatPlainText(string& plainText){

        string formattedText;

        for(char c: plainText){
            if(c == 'j') c= 'i';
            if(isalpha(c)){
                formattedText += tolower(c);
            }
        }
        // cout<<formattedText<<" ";
        int length = formattedText.length();
        for(int i=0; i<length; i+=2){
            if(i+1 == length)
                    formattedText+= 'x';                    //appending x if last char has no pair
            else if(formattedText[i] == formattedText[i+1]){
                formattedText.insert(i+1,"x");                 //insert x if two same letters in pair
                length++;
                i++;
            }
        }

        return formattedText;
    }

    string encrypt(string & plainText, vector<vector<char>> &matrix, unordered_map<char,pair<int,int>> &position){
        
        string cipherText;
        int length = plainText.length();

        for(int i =0; i<length;i+=2){
            char a = plainText[i];
            char b = plainText[i+1];

            int row1 = position.at(a).first;
            int col1 = position.at(a).second ; 
            
            int row2 = position.at(b).first;
            int col2 = position.at(b).second ; 

            if(row1 == row2){                   // same row
                cipherText += matrix[row1][(col1 + 1)%5];
                cipherText += matrix[row2][(col2 + 1)%5];

            }
            else if(col1 == col2){              //same col
                cipherText += matrix[(row1+1)%5][col1];
                cipherText += matrix[(row2+1)%5][col2];
            }
            else{
                cipherText += matrix[row1][col2];
                cipherText += matrix[row2][col1];
            }

        }

        return cipherText;
    }


};


int main(){
    PlayfairCipher obj;

    string plainText = "Sanjivani";
    string key = "ldrp";

    vector<vector<char>> matrix(5,vector<char>(5));
    unordered_map<char, pair<int,int>> position;
    
    obj.generateMatrix(key,matrix,position);
    string formattedText = obj.formatPlainText(plainText);
    string cipherText = obj.encrypt(formattedText,matrix,position);

    cout<<cipherText;
}