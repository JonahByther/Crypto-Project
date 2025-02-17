#include <iostream>
#include <fstream>
#include <string>
#include "vigenereCryption.h"

using namespace std;

void vigenereCryption(string filename, string key, bool encrypt){
    ifstream inputFile(filename);
    string outputFilename;
    string text;
    char base;

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    if (encrypt){
        outputFilename = "encrypted_vigenere.txt";
    }
    else{
        outputFilename = "decrypted_vigenere.txt";
    }
    ofstream outputFile(outputFilename);
    getline(inputFile, text, '\0');

    for (size_t i = 0; i < text.length(); i++){
        if (isalpha(text[i])){
            if(isupper(text[i])){
                base = 'A';
            }
            else{
                base = 'a';
            }
            int shift = key[i % key.length()] - base;
            if(encrypt){
                text[i] = (text[i] - base + shift) % 26 + base;
            }
            else{
                text[i] = (text[i] - base - shift + 26) % 26 + base;
            }
        }
    }
    outputFile << text;
    cout << "Cryption saved to " << outputFilename << endl;
    inputFile.close();
    outputFile.close();
}