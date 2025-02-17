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

    /*This checks the see if the character is uppercase or lowercase, then based on that, if it
        is encrypting, it replaces the character with a specific equation, and if it is decrypting, then it 
        replaces that character with a different equation that basically reverses what it did in the other one.
    */
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