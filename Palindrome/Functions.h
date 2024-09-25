#pragma once

#include <string>
#include <cctype>
#include <sstream>
#include "Stack.cpp"


void MainMenu();
bool isPalindrome(int max, int choice, Stack<char> &palindrome);


void MainMenu(){

        cout << "\n------------- Main Menu -------------\n";
        cout << "\nSelect the type of string input:\n";
        cout << "1. Alphanumeric String\n";
        cout << "2. Alphabetic String\n";
        cout << "3. Numeric String\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";

}


bool isPalindrome(int max, int choice, Stack<char> &palindrome) {
    int alphaCount, numericCount;
    string inputString = "", filteredString = "", PoppedString = "";

   
    if(choice == 1){
        do {
            alphaCount = 0;
            numericCount = 0;

            cout << "\nEnter a String: ";
            getline(cin, inputString);

            for (int i = 0; i < inputString.length(); i++) {
                if (isalnum(inputString[i])) {
                    if (isalpha(inputString[i])) {
                        alphaCount++;
                    } else if (isdigit(inputString[i])) {
                        numericCount++;
                    }
                }
            }

            if ((alphaCount + numericCount) > max) {
                cout << "\nStack Overflow! Too many alphanumeric characters.";
                cout << "\nEnter Again!\n";
            } else if (alphaCount == 0 && numericCount == 0) {
                cout << "\nNo valid alphanumeric characters found.";
                cout << "\nEnter Again!\n";
            }
        } while ((alphaCount + numericCount) > max || (alphaCount == 0 && numericCount == 0));

    } else if (choice == 2) { 
        do { 
            alphaCount = 0;
            numericCount = 0;
            cout << "\nEnter a String: ";
            getline(cin, inputString);

            for (int i = 0; i < inputString.length(); i++) {
                if (isalpha(inputString[i])) {
                    alphaCount++;
                }else if(isdigit(inputString[i])){
                    numericCount++;
                }
            }

            if (alphaCount > max) {
                cout << "\nStack Overflow! Too many alphabetic characters.";
                cout << "\nEnter Again!\n";
            } else if (alphaCount == 0) {
                cout << "\nNo alphabetic characters found.";
                cout << "\nEnter Again!\n";
            }else if(numericCount > 0){
                cout << "\nNumeric characters found.";
                cout << "\nEnter Again!\n";
            }
        } while (alphaCount > max || alphaCount == 0 || numericCount > 0);

    } else if (choice == 3) { 
        do { 
            numericCount = 0;
            alphaCount = 0;
            cout << "\nEnter a String: ";
            getline(cin, inputString);

            for (int i = 0; i < inputString.length(); i++) {
                if (isdigit(inputString[i])) {
                    numericCount++;
                }else if(isalpha(inputString[i])){
                    alphaCount++;
                }
            }

            if (numericCount > max) {
                cout << "\nStack Overflow! Too many numeric characters.";
                cout << "\nEnter Again!\n";
            } else if (numericCount == 0) {
                cout << "\nNo numeric characters found.";
                cout << "\nEnter Again!\n";
            }else if(alphaCount > 0){
                cout << "\nAlphabetic characters found.";
                cout << "\nEnter Again!\n";
            }
        } while (numericCount > max || numericCount == 0 || alphaCount > 0);
    }

    for (int i = 0; i < inputString.length(); i++) {
        if (choice == 1) {
            if (isalnum(inputString[i])) {
                filteredString += tolower(inputString[i]);
                palindrome.Push(tolower(inputString[i]));  
            }
        } else if (choice == 2) { 
            if (isalpha(inputString[i])) {
                filteredString += tolower(inputString[i]); 
                palindrome.Push(tolower(inputString[i])); 
            }
        } else if (choice == 3) { 
            if (isdigit(inputString[i])) {
                filteredString += inputString[i];  
                palindrome.Push(inputString[i]);  
            }
        }
    }

    while (!palindrome.isEmpty()) {
        char item;
        palindrome.Pop(item);
        PoppedString += item; 
    }

    return PoppedString == filteredString;
}
