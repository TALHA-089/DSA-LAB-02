#include <string>
#include "Stack.cpp"
#include <iostream>
#include <cctype>

using namespace std;

int main() {

    int max, choice, alphaCount, numericCount;
    string myString0, myString1, myString2;
    char continueChoice;

    do {
        cout << "\n\nPALINDROME CHECKER\n";

        alphaCount = 0;
        numericCount = 0;
        myString0 = "";
        myString1 = "";
        myString2 = "";

        cout << "\nSelect the type of string input:\n";
        cout << "1. Alphanumeric String\n";
        cout << "2. Alphabetic String\n";
        cout << "3. Numeric String\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); 

        cout << "\nEnter the maximum size for alphabetic or numeric characters: ";
        cin >> max;
        cin.ignore();

        Stack<char>* palindrome = new Stack<char>(max);

        do {
            alphaCount = 0;
            numericCount = 0;
            myString0 = "";
            myString2 = "";  

            cout << "\nEnter a String: ";
            getline(cin, myString1);


            switch (choice) {
            case 1: 
                for (int i = 0; i < myString1.length(); i++) {
                    if (isalnum(myString1[i])) {
                        if (isalpha(myString1[i])) alphaCount++;
                        else if (isdigit(myString1[i])) numericCount++;
                    }
                }
                if (alphaCount + numericCount > max) {
                    cout << "\nStack Overflow! Too many alphanumeric characters.";
                    cout << "\nEnter Again!\n";
                } else if (alphaCount == 0 && numericCount == 0) {
                    cout << "\nNo valid alphanumeric characters found.";
                    cout << "\nEnter Again!\n";
                }
                break;

            case 2: 
                for (int i = 0; i < myString1.length(); i++) {
                    if (isalpha(myString1[i])) {
                        alphaCount++;
                    }
                }
                if (alphaCount > max) {
                    cout << "\nStack Overflow! Too many alphabetic characters.";
                    cout << "\nEnter Again!\n";
                } else if (alphaCount == 0) {
                    cout << "\nNo alphabetic characters found.";
                    cout << "\nEnter Again!\n";
                }
                break;

            case 3: 
                for (int i = 0; i < myString1.length(); i++) {
                    if (isdigit(myString1[i])) {
                        numericCount++;
                    }
                }
                if (numericCount > max) {
                    cout << "\nStack Overflow! Too many numeric characters.";
                    cout << "\nEnter Again!\n";
                } else if (numericCount == 0) {
                    cout << "\nNo numeric characters found.";
                    cout << "\nEnter Again!\n";
                }
                break;

            default:
                cout << "\nInvalid choice. Please enter 1, 2, or 3.";
                return 1;
            }

      
        } while ((choice == 1 && (alphaCount + numericCount > max || (alphaCount == 0 && numericCount == 0))) ||
                (choice == 2 && (alphaCount > max || alphaCount == 0)) ||
                (choice == 3 && (numericCount > max || numericCount == 0)));


        for (int i = 0; i < myString1.length(); i++) {
         
            if (choice == 1) { 
                if (isalnum(myString1[i])) {
                    myString0 += tolower(myString1[i]); 
                    palindrome->Push(tolower(myString1[i]));
                }
            } else if (choice == 2) { 
                if (isalpha(myString1[i])) {
                    myString0 += tolower(myString1[i]); 
                    palindrome->Push(tolower(myString1[i]));
                }
            } else if (choice == 3) { 
                if (isdigit(myString1[i])) {
                    myString0 += myString1[i];  
                    palindrome->Push(myString1[i]);
                }
            }
        }


        while (!palindrome->isEmpty()) {
            char item;
            palindrome->Pop(item);
            myString2 += item;
        }

   
        if (myString0 == myString2) {
            cout << "\nString is a Palindrome\n";
        } else {
            cout << "\nString is not a Palindrome\n";
        }


        cout << "\nDo you want to check another string? (y/n): ";
        cin >> continueChoice;
        cin.ignore();  

    } while (tolower(continueChoice) == 'y'); 

    cout << "\nThank you for using the Palindrome Checker!\n";
    return 0;
}
