#include "Functions.h"


int main(){

    int max, numericCount, choice;
    string inputString, Choice, Max;

    do{
        max = 0;
        numericCount = 0;
        inputString = "";

         do {
                MainMenu();
                getline(cin,Choice);

                for(int i = 0; i < Choice.length(); i++){
                    if(isdigit(Choice[i])){
                        numericCount++;
                    }
                } 

                if(numericCount > 0){
                    stringstream ss(Choice);
                    ss >> choice;
                    cin.ignore();

                    if(choice > 4 || choice < 1){
                    cout << "\nInvalid choice\n";
                    cout << "\nEnter Again!\n";
                    }
                }else{
                    cout << "\nInvalid input!\n";
                    cout << "\nEnter Again!\n";
                }

            } while(choice > 4 || choice < 1);

                if(choice == 4){
                    cout << "\nThank you for using Palindrome Checker!\n";
                    return 0;
                }

                do{
                    cout << "\nEnter the maximum size for alphabetic or numeric characters: ";
                    getline(cin, Max);
                    numericCount = 0;
                    for(int i = 0; i < Choice.length(); i++){
                        if(isdigit(Choice[i])){
                            numericCount++;
                        }
                    } 

                    if(numericCount > 0){
                        stringstream ss(Max);
                        ss >> max;
                        cin.ignore();
                        if(max <= 2){
                            cout << "\nPlease Enter a Positive Number greater than 2.\n";
                        }

                    }else{
                        cout << "\nPlease Enter a Number!\n";
                        cout << "\nEnter Again!";
                    }
                }while(numericCount <= 0 || max <= 2);
                

                Stack<char>* palindrome = new Stack<char>(max);

                if(isPalindrome(max, choice, *palindrome)){
                    cout << "\nString is a Palindrome\n";
                }else{
                    cout << "\nString is not a Palindrome\n";
                }
                delete palindrome;

    }while(choice != 4);

    return 0;
}
