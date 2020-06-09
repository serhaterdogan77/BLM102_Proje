#include <iostream>
#include <fstream>
#include <string>
#include<cctype>

using namespace std;

// Maximum number of names in input file
const int MAX_NAMES = 100;

// Name of file containing names and phone numbers
const string PHONEBOOK_FILENAME = "phonebook.txt";


struct Person
{
	string name;
	string surname;
	string phone;
	string workphone;
	string id;


	Person()
	{
		name = "";
		surname = "";
		phone = "";
		workphone = "";
		id = "";
	}

	bool Matches(string x)
	{



		return (id.find(x) != string::npos);
	}

	bool Matches1(string x)
	{



		return (name.find(x) != string::npos);
	}

	bool Matches2(string x)
	{



		return (surname.find(x) != string::npos);
	}
	bool Matches3(string x)
	{



		return (phone.find(x) != string::npos);
	}
	bool Matches4(string x)
	{



		return (workphone.find(x) != string::npos);
	}




};

// Read all people in from data file.
// [out] people - Array that will contain all people from the data file
// [out] num_people - Number of people in the data file
void ReadAllPeople(Person people[], int& num_people)
{
	ifstream fin;
	fin.open(PHONEBOOK_FILENAME.c_str(), ios::app);
	if (fin.fail())
	{
		cout << "Dosya acilamiyor " << PHONEBOOK_FILENAME << endl;
		return;
	}

	int i = 0;
	
	while (!fin.eof() && i < MAX_NAMES)
	{
		
		getline(fin, people[i].name);
		getline(fin, people[i].surname);
		getline(fin, people[i].phone);
		getline(fin, people[i].workphone);
		getline(fin, people[i].id);

		i++;

		// Be careful not to read outside the array bounds
		if (i < MAX_NAMES)
			getline(fin, people[i].name);
		getline(fin, people[i].surname);
		getline(fin, people[i].phone);
		getline(fin, people[i].workphone);
		getline(fin, people[i].id);
	}

	num_people = i;

	fin.close();
}

// Save all the people in the array to the data file.
// [in] people - Array to write to file
// [in] num_people - Number of people in the array
void SaveToFile(const Person people[], int num_people)
{
	ofstream fout;

	fout.open(PHONEBOOK_FILENAME.c_str());

	for (int i = 0; i < num_people; i++)
	{
		fout << people[i].name << endl;
		fout << people[i].surname << endl;
		fout << people[i].phone << endl;
		fout << people[i].workphone << endl;
		fout << people[i].id << endl;
	}

}

// Append this person to the data file.
// [in] person - Person to be appended to the file
void AppendToFile(Person person)
{
	ofstream fin;
	fin.open(PHONEBOOK_FILENAME.c_str(), ios::app);

	fin << person.name << endl;
	fin << person.surname << endl;
	fin << person.phone << endl;
	fin << person.workphone << endl;
	fin << person.id << endl;


	fin.close();




}

// Read a name and phone number from the keyboard, add a new person to
// the array, and save the person to file using AppendToFile.
// [in/out] people - Array that the new person is added to
// [in/out] num_people - The number of people in the array (1 more once
//					   the new person is added)
void AddName(Person people[], int& num_people)
{
	Person person;


	cout << "\nIsim: ";
	getline(cin, person.name);

	cout << "\nSoyisim: ";
	getline(cin, person.surname);

	cout << "Numara: ";
	getline(cin, person.phone);

	cout << "Is numarasi: ";
	getline(cin, person.workphone);

	cout << "Id: ";
	getline(cin, person.id);

	for (int i = 0; i < num_people; i++)
	{
		if (i+1 == num_people)
			people[num_people] = person;
	}
	num_people++;


	AppendToFile(person);
	cout << "\n\nKisi eklendi. " << endl;





}

// Ask the for person's name to change, find the person in the array and
// change it to the new phone number.  Then save the new data to file by
// calling SaveToFile.
// [in/out] people - Array containing people
// [in]	 num_people - Number of people in the array
void ChangePhone(Person people[], int num_people)
{
	Person person;
	int count;

	cout << "duzenlemek istediginiz kisinin id'sini giriniz: ";
	getline(cin, person.name);


	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches(person.id))
		{
			cout << endl << people[count].name << " " << people[count].surname << endl;


			cout << "\nYeni numara giriniz: ";
			getline(cin, people[count].phone);

			cout << "\nYeni is numarasi giriniz: ";
			getline(cin, people[count].workphone);

			cout << "\nIsim giriniz: ";
			getline(cin, people[count].name);

			cout << "\nSoyisim giriniz: ";
			getline(cin, people[count].surname);

			cout << "\nId: ";
			getline(cin, people[count].id);

			SaveToFile(people, num_people);

			cout << "\n\nKisi kaydedildi.";

			return;

		}

	}

	if (count = num_people)
		cout << "\nKisi bulunamadi.";


}

// Ask the user for a name to find and show all occurrences of the name
// in the given array.
// [in] people - Array containing people
// [in] num_people - Number of people in the array

void FindNameId(Person people[], int num_people) {
	Person person;
	int count;


	cout << "Aramak istediginiz kisinin id'sini giriniz: ";
	cin >> person.id;


	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches(person.id))
		{
			cout <<people[count].name << " " << people[count].surname << endl;

			cout << "Numarasi:  " << people[count].phone;
			cout << " Is numarasi: " << people[count].workphone;
		}
	}
}

void FindNameNam(Person people[], int num_people) {
	Person person;
	int count;


	cout << "Aramak istediginiz kisinin ismini giriniz: ";
	cin >> person.name;

	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches1(person.name))
		{
			cout << people[count].name << " " << people[count].surname << endl;

			cout << "Numarasi:  " << people[count].phone;
			cout << " Is numarasi: " << people[count].workphone;
		}
	}
}

void FindNameSur(Person people[], int num_people) {
	Person person;
	int count;


	cout << "Aramak istediginiz kisinin soyismini giriniz: ";
	cin >> person.surname;

	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches2(person.surname))
		{
			cout << people[count].name << " " << people[count].surname << endl;

			cout << "Numarasi:  " << people[count].phone;
			cout << " Is numarasi: " << people[count].workphone;
		}
	}
}

void FindNamePhone(Person people[], int num_people) {
	Person person;
	int count;


	cout << "Aramak istediginiz kisinin telefon numarasini giriniz: ";
	cin >> person.phone;

	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches3(person.phone))
		{
			cout <<people[count].name << " " << people[count].surname << endl;

			cout << "Numarasi:  " << people[count].phone;
			cout << " Is numarasi: " << people[count].workphone;
		}
	}
}

void FindNameWorkPhone(Person people[], int num_people) {
	Person person;
	int count;
	

	cout << "Aramak istediginiz kisinin is numarasini giriniz: ";
	cin >> person.workphone;

	for (count = 0; count < num_people; count++)
	{
		if (people[count].Matches4(person.workphone))
		{
			cout <<people[count].name << " " << people[count].surname << endl;

			cout << "Numarasi:  " << people[count].phone;
			cout << " Is numarasi: " << people[count].workphone;
		}
	}
}


void FindName(Person people[], int num_people)
{
	

	Person person;
	int count;
	char x;
	cout << "Kisiyi hangi ozelligi ile aramak istersiniz: ";
	
	do{
		cout << "\n\nA - id ile\n";
		cout << "D - isim ile\n";
		cout << "C - Soyisim ile\n";
		cout << "F - Numarasi ile\n";
		cout << "l - Is numarasi ile\n";
		cout << "Q - Geri git\n";
		cin >> x;
		cin.get();   // Read EOL

		x = toupper(x);
			switch (x)
			{
			case 'A':	FindNameId(people, num_people);		break;
			case 'D':	FindNameNam(people, num_people);		break;
			case 'C':	FindNameSur(people, num_people);	break;
			case 'F':	FindNamePhone(people, num_people);		break;
			case 'L':	FindNameWorkPhone(people, num_people);		break;

			}
		} while (x != 'Q' && x != 'q');
}

// Display all names and numbers.
// [in] people - Array containing people
// [in] num_people - Number of people in the array
void ListAllNames(const Person people[], int num_people)
{
	cout << "\n\nTum kayitlar:\n";
	for (int i = 0; i < num_people; i++)
		cout << people[i].name << " " << people[i].surname << " " << people[i].phone << " " << people[i].workphone <<" "<<people[i].id<<endl;
}


void DeletePerson(Person people[], int num_people) {
	Person person;
	int count;


	cout << "Silmek kisinin id'sini giriniz: ";
	cin >> person.id;


	for (count = 0; count < num_people; count++) {

		if (people[count].Matches(person.id)) {

			people[count].name = "";
			people[count].surname = "";
			people[count].phone = "";
			people[count].workphone = "";
			people[count].id = "";

			cout << "Kisi basariyla silindi.";
		}

	}
	
	
}

int main()
{
	Person people[MAX_NAMES];
	int num_people;

	// Get records from file
	ReadAllPeople(people, num_people);

	char choice;

	do
	{
		cout << "\n\nA - Kisi ekle\n";
		cout << "D - Kisi silme\n";
		cout << "C - Kisi duzenle\n";
		cout << "F - Kisi ara\n";
		cout << "L - Tum kisileri listele\n";
		cout << "Q - Cikis yap\n\n";	
		cout << "Secim? ";
		cin >> choice;
		cin.get();   // Read EOL

		choice = toupper(choice);

		switch (choice)
		{
		case 'A':	AddName(people, num_people);		break;
		case 'D':	DeletePerson(people, num_people);		break;
		case 'C':	ChangePhone(people, num_people);	break;
		case 'F':	FindName(people, num_people);		break;
		case 'L':	ListAllNames(people, num_people);	break;
		}
	} while (choice != 'Q' && choice != 'q');
}