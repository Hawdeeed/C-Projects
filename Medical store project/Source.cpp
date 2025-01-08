
# include<iostream>
# include<fstream>
# include<string>
using namespace std;
int insertFunction(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	while (true) {
		char choice = ' ';
		cout << "Insert the following details " << endl;
		cout << "Name of a medicine " << endl;
		cin >> Name[s];
		cout << "Formula of a medicine " << endl;
		cin >> Formula[s];
		cout << "Dosage of a medicine " << endl;
		cin >> Dose[s];
		cout << "MFG date of a medicine " << endl;
		cin >> Mfg[s];
		cout << "Expiry date of a medicine " << endl;
		cin >> Exp[s];
		cout << "Prize of a medicine " << endl;
		cin >> pz[s];
		cout << "Quantity of a medicine " << endl;
		cin >> q[s];
		s++;
		ofstream fout;
		fout.open("medicines.txt");
		for (int i = 0; i < s; i++) {
			fout << Name[i] << " " << Formula[i] << " " << Dose[i] << " " << Mfg[i] << " " << Exp[i] << " " << pz[i] << " " << q[i];
			fout << endl;
		}
		fout.close();
		cout << "Do you want to stop inserting? then (press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			return s;
		}
	}
}
int Delete(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	cout << s;
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			cout << "Name of a medicine " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					Name[i] = Name[i + 1];
					Formula[i] = Formula[i + 1];
					Dose[i] = Dose[i + 1];
					Mfg[i] = Mfg[i + 1];
					Exp[i] = Exp[i + 1];
					pz[i] = pz[i + 1];
					q[i] = q[i + 1];
					check = true;
				}
				if (check == true) {
					Name[i] = Name[i + 1];
					Formula[i] = Formula[i + 1];
					Dose[i] = Dose[i + 1];
					Mfg[i] = Mfg[i + 1];
					Exp[i] = Exp[i + 1];
					pz[i] = pz[i + 1];
					q[i] = q[i + 1];
				}
				ofstream fout;
				fout.open("medicines.txt");
				for (int i = 0; i < s - 1; i++) {
					fout << Name[i] << " " << Formula[i] << " " << Dose[i] << " " << Mfg[i] << " " << Exp[i] << " " << pz[i] << " " << q[i];
					fout << endl;
				}
				fout.close();
			}
			if (check == false) {
				cout << "You entered the wrong name." << endl;
			}
			else {
				break;
			}
		}
		s--;
		cout << "Do you want to stop deleting? then (press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			break;
		}
	}
	return s;
}
void updateQuantity(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			int number = 0;
			cout << "Name of a medicine " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					cout << "Your quantity is " << q[i] << endl;
					cout << "Enter the quantity you want to replace " << endl;
					cin >> number;
					q[i] = number;
					ofstream fout;
					fout.open("medicines.txt");
					for (int i = 0; i < s; i++) {
						fout << Name[i] << " " << Formula[i] << " " << Dose[i] << " " << Mfg[i] << " " << Exp[i] << " " << pz[i] << " " << q[i];
						fout << endl;
					}
					fout.close();
					check = false;
					break;
				}
				else {
					check = true;
				}

			}
			if (check == true) {
				cout << "You entered the wrong name." << endl;
			}
			else {

				break;
			}
		}
		cout << "Do you want to stop updating quantity? then (press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			break;
		}
	}
}
void updatePrice(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			int number = 0;
			cout << "Name of a medicine " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					cout << "Price of this medicine is " << pz[i] << endl;
					cout << "Enter the new price" << endl;
					cin >> number;
					pz[i] = number;
					ofstream fout;
					fout.open("medicines.txt");
					for (int i = 0; i < s; i++) {
						fout << Name[i] << " " << Formula[i] << " " << Dose[i] << " " << Mfg[i] << " " << Exp[i] << " " << pz[i] << " " << q[i];
						fout << endl;
					}
					fout.close();
					check = false;
					break;
				}
				else {
					check = true;
				}

			}
			if (check == true) {
				cout << "You entered the wrong name." << endl;
			}
			else {
				break;
			}
		}
		cout << "Do you want to stop updating price? then (press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			break;
		}
	}
}
void searchPrice(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			bool check = false;
			int number = 0;
			cout << "Enter name of a medicine of which you want to check price " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					cout << "Prize of this medicine is " << pz[i] << endl;
					check = false;
					break;
				}
				else {
					check = true;
				}
			}
			if (check == true) {
				cout << "You entered the wrong name." << endl;
			}
			else {
				break;
			}
		}
		cout << "Do you want to stop searching for prices? then(press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			break;
		}
	}
}
void remainingQuantity(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			bool check = false;
			int number = 0;
			cout << "Enter name of a medicine of which you want to check price " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					cout << "Remaining quantity of this medicine is " << q[i] << endl;
					check = false;
					break;
				}
				else {
					check = true;
				}
			}
			if (check == true) {
				cout << "You entered the wrong name." << endl;
			}
			else {
				break;
			}
		}
		cout << "Do you want to stop searching for remaining quantities? then(press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			break;
		}
	}
}
void Perchase(string Name[50], string Formula[50], string Dose[50], string Mfg[50], string Exp[50], double pz[50], double q[50], int s) {
	double bill = 0;
	double price = 0;
	while (true) {
		char choice = ' ';
		bool check = false;
		string name;
		while (true)
		{
			bool check = false;
			int number = 0;
			cout << "Enter name of a medicine: " << endl;
			cin >> name;
			for (int i = 0; i < s; i++)
			{
				if (name == Name[i])
				{
					int qu;
					cout << "How much you want? ";
					cin >> qu;
					if (qu < q[i])
					{
						q[i] = q[i] - qu;
						price = pz[i] * qu;
						bill = bill + price;
						fstream fout;
						fout.open("recept.txt", ios::app);
						cout << "Name: " << name << ", Quantity: " << qu << ", Price: " << price << endl;
						fout << "Name: " << name << ", Quantity: " << qu << ", Price: " << price << endl;
						fout.close();
						fout.open("medicines.txt", ios::out);
						for (int j = 0; j < s; j++) {
							fout << Name[j] << " " << Formula[j] << " " << Dose[j] << " " << Mfg[j] << " " << Exp[j] << " " << pz[j] << " " << q[j];
							fout << endl;
						}
						fout.close();
					}
					else {
						cout << "Quantity of this medicine is less " << endl;
					}
					cout << "You have " << q[i] << " left" << endl;
					check = false;
					break;
				}
				else {
					check = true;
				}

			}
			if (check == true) {
				cout << "You entered the wrong name." << endl;
			}
			else {

				break;
			}
		}
		cout << "Do you want to stop perchasing? then(press y) or if done press any button" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			bill = bill + (bill * 0.05);
			fstream fout;
			fout.open("recept.txt", ios::app);
			cout << "Total bill after 5% tax: Rs." << bill << endl;
			fout << "Total bill after 5% tax: Rs." << bill << endl;
			fout << endl;
			fout.close();
			break;
		}
	}
}
int main() {
	int size = 0;
	string n;
	string f;
	string d;
	string m;;
	string e;
	double p;
	double q;
	ifstream in;
	in.open("medicines.txt");
	while (!in.eof()) {
		in >> n >> f >> d >> m >> e >> p >> q;
		size++;
	}
	in.close();
	string name[50];
	string formula[50];
	string dosage[50];
	string mfgDate[50];
	string expDate[50];
	double prize[50];
	double quantity[50];
	ifstream fin;
	fin.open("medicines.txt");
	for (int i = 0; i < size; i++) {
		fin >> name[i] >> formula[i] >> dosage[i] >> mfgDate[i] >> expDate[i] >> prize[i] >> quantity[i];
	}
	fin.close();
	int press = 0;
	cout << "WElCOME to Pharmacy Store Management!" << endl;
	while (true) {
		cout << "----------------------------------------" << endl;
		cout << "Press 0 to exit. " << endl;
		cout << "Press 1 if you want to insert " << endl;
		cout << "Press 2 if you want to delete " << endl;
		cout << "Press 3 if you want to update quantity of any medicine " << endl;
		cout << "Press 4 if you want to update price of any medicine " << endl;
		cout << "Press 5 to search price of any medicine " << endl;
		cout << "Press 6 to search remaining quantity of any medicine " << endl;
		cout << "Press 7 to perchase medicine " << endl;
		cout << "-------------------------------------------" << endl;
		cin >> press;
		if (press == 1) {
			size = insertFunction(name, formula, dosage, mfgDate, expDate, prize, quantity, size);
			cout << "Medicine is inserted " << endl;
			cout << "---------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++) {
				cout << name[i] << " " << formula[i] << " " << dosage[i] << " " << mfgDate[i] << " " << expDate[i] << " " << prize[i] << " " << quantity[i] << " ";
				cout << endl;
			}
			cout << "---------------------------------------------------------" << endl;

		}
		if (press == 2) {
			size = Delete(name, formula, dosage, mfgDate, expDate, prize, quantity, size);
			cout << size;
			cout << "---------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++) {
				cout << name[i] << " " << formula[i] << " " << dosage[i] << " " << mfgDate[i] << " " << expDate[i] << " " << prize[i] << " " << quantity[i] << " ";
				cout << endl;
			}
			cout << "---------------------------------------------------------" << endl;

		}
		if (press == 3) {
			updateQuantity(name, formula, dosage, mfgDate, expDate, prize, quantity, size);

		}
		if (press == 4) {
			updatePrice(name, formula, dosage, mfgDate, expDate, prize, quantity, size);
		}
		if (press == 5) {
			searchPrice(name, formula, dosage, mfgDate, expDate, prize, quantity, size);

		}
		if (press == 6) {
			remainingQuantity(name, formula, dosage, mfgDate, expDate, prize, quantity, size);

		}
		if (press == 7) {
			Perchase(name, formula, dosage, mfgDate, expDate, prize, quantity, size);
		}
		if (press == 0) {
			break;
		}
	}
	system("pause");
	return 0;
}











