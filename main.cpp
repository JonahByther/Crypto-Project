/*
Crypto Project - Jonah, Yusuf, John
2/16/2025
CSC4420
This project takes a file and can encrypt and decrypt the file using a caesar cipher and a vigenere cipher.
A caesar cipher is encrypted/decrypted with an integer, and a vigenere cipher is encrypted/decrypted with a string.
*/
#include <iostream>
#include "caesarCryption.h"
#include "vigenereCryption.h"

using namespace std;

int main() {
  int choice;
  string filename;
  
  cout << "File Encryption/Decryption Program" << endl;
  cout << "1. Encrypt using a caesar Cipher" << endl;
  cout << "2. Decrypt using a caesar Cipher" << endl;
  cout << "3. Encrypt using Vigenere Cipher" << endl;
  cout << "4. Decrypt using Vigenere Cipher" << endl;
  cout << "5. Exit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  if (choice == 5) return 0;
  
  cout << "Enter filename: ";
  cin >> filename;
  
  switch (choice) {
      case 1: {
          int key;
          cout << "Enter shift key(number): "; //key is based on a number
          cin >> key;
          caesarCryption(filename, key, true);
          break;
      }
      case 2: {
          int key;
          cout << "Enter shift key(number): "; //key is based on a number
          cin >> key;
          caesarCryption(filename, key, false);
          break;
      }
      case 3: {
          string key;
          cout << "Enter Vigenere key(string): "; //key is based on a string
          cin >> key;
          vigenereCryption(filename, key, true);
          break;
      }
      case 4: {
        string key;
            cout << "Enter Vigenere key(string): "; //key is based on a string
            cin >> key;
            vigenereCryption(filename, key, false);
            break;
      }
      default:
          cout << "Invalid choice!" << endl;
  }
  
  return 0;
}