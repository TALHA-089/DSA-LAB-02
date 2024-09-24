#include<string>
#include "Stack.cpp"


int main() {

	Stack<char> palindrome(10);

	string myString1;

	cout << "\nEnter a String: ";
	getline(cin, myString1);

	for (int i = 0; i < myString1.length(); i++) {
		char item = myString1[i];
		palindrome.Push(item);
	}

	string myString2;

	for (int i = 0; i < myString1.length(); i++) {
		char item;
		palindrome.Pop(item);
		myString2 += item;
	}

	if (myString1 == myString2) {
		cout << "\nIs a Palindrome\n";
	}
	else {
		cout << "\nIs not a Palindrome\n";
	}

	system("Pause");
	return 0;
}