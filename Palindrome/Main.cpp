#include<string>
#include "Stack.cpp"

int main() {

	int max;

	cout << "\Enter the Size of your Palindrome: ";
	cin >> max;
	cin.ignore();

	Stack<char>* palindrome = new Stack<char>(max);

	string myString1;

	cout << "\nEnter a String: ";
	getline(cin, myString1);

	for (int i = 0; i < myString1.length(); i++) {

		if (isalpha(myString1[i])) {
			myString1[i] = tolower(myString1[i]);
			char item = myString1[i];
			palindrome->Push(item);
		}
	}

	string myString2;

	while (!palindrome->isEmpty()) {
		char item;
		palindrome->Pop(item);
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