#include <iostream>
#include <fstream>
#include <string>
#include "caesarCryption.h"

using namespace std;

void caesarCryption(string filename, int key, bool encrypt){
    ifstream inputFile(filename);
    string outputFilename;
    char ch;
    char base;

    if(!inputFile){
        cerr << "Error opening file" << endl;
        return;
    }

    if (encrypt){
        outputFilename = "encrypted_caesar.txt";
    }
    else{
        outputFilename = "decrypted_caesar.txt";
    }

    ofstream outputFile(outputFilename);

    while(inputFile.get(ch)){
        if(isalpha(ch)){
            if(isupper(ch)){
                base = 'A';
            }
            else{
                base = 'a';
            }

            if(encrypt){
                ch = (ch - base + key) % 26 + base;
            }
            else{
                ch = (ch - base - key + 26) % 26 + base;
            }
        }
        outputFile.put(ch);
    }

    cout << "Cryption saved to " << outputFilename << endl;
    inputFile.close();
    outputFile.close();
}