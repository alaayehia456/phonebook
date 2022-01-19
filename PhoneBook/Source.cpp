#include <iostream>
#include <fstream>
using namespace std;

struct PhoneBookEntry
{
	char FirstName[100];
	char LastName[100];
	char PhoneNumber[20];
};

void PrintPhoneBook(PhoneBookEntry* phoneBook, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << phoneBook[i].FirstName << " " << phoneBook[i].LastName << " "
			<< phoneBook[i].PhoneNumber << endl;
	}
}

void main()
{
	ifstream fileIn;
	fileIn.open("phonebook.txt");
	int count = 0, oldCount = 0;
	PhoneBookEntry* currentBook = 0;
	if (fileIn.is_open())
	{
		fileIn >> oldCount;
		currentBook = new PhoneBookEntry[oldCount];

		for (int i = 0; i < oldCount; i++)
		{
			fileIn >> currentBook[i].FirstName;
			fileIn >> currentBook[i].LastName;
			fileIn >> currentBook[i].PhoneNumber;
		}
		fileIn.close();
	}

	ofstream fileOut;
	fileOut.open("phonebook.txt");
	
	cout << "Enter how many phone numbers you want to input: ";
	cin >> count;

	PhoneBookEntry* phoneBook = new PhoneBookEntry[count];
	for (int i = 0; i < count; i++)
	{
		cout << "Enter first name: ";
		cin >> phoneBook[i].FirstName;

		cout << "Enter last name: ";
		cin >> phoneBook[i].LastName;

		cout << "Enter phone number: ";
		cin >> phoneBook[i].PhoneNumber;
		cout << "Entry " << i + 1 << " Done!" << endl << endl;
	}

	cout << endl << endl << "Printing whole phone phone: " << endl;
	if (currentBook != 0)
	{
		PrintPhoneBook(currentBook, oldCount);
	}
	PrintPhoneBook(phoneBook, count);

	//Save old + new
	fileOut << oldCount + count << endl;
	if (currentBook)
	{
		for (int i = 0; i < oldCount; i++)
		{
			fileOut << currentBook[i].FirstName << endl;
			fileOut << currentBook[i].LastName << endl;
			fileOut << currentBook[i].PhoneNumber << endl;
		}
	}

	for (int i = 0; i < count; i++)
	{
		fileOut << phoneBook[i].FirstName << endl;
		fileOut << phoneBook[i].LastName << endl;
		fileOut << phoneBook[i].PhoneNumber << endl;
	}

	fileOut.close();

	if (currentBook)
	{
		delete[] currentBook;
	}

	delete[] phoneBook;
}