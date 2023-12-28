#include "shopping.h"



void shopping::menu() {
	int choice;
	
	string email, password;
	while (loop) {
		cout << "\n-----------------------------------------------------------------------------------------------------------------  \n";
		cout << endl;
		cout << "|\t\t\t\tWelcome to Ahraf and Ayesha's Mart\t\t\t\t|" << endl;
		cout << endl;
		cout << "\n-----------------------------------------------------------------------------------------------------------------  \n";
		cout << "1)Administrator" << endl;
		cout << "2)Buyer" << endl;
		cout << "3)Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Please enter email:" << endl;
			cin >> email;
			cout << "Please enter password:" << endl;
			cin >> password;
			if (email == "123" && password == "123")
				administrator();
			else cout << " Invalid Credentials." << endl;
			break;
		case 2: buyer();
			break;
		case 3: loop = 0; 
			cout << "Hope you had a good expereince." << endl;
			break;
		default:
			cout << "Enter the correct choice." << endl;
		}
	}
}


void shopping::administrator() {
	int choice;
	bool loop1 = 1;
	while (loop1) {
		cout << "\n---------------------------------------------------------------------------------------------------------------  \n";
		cout << endl;
		cout << "|\t\t\t\tWelcome to the Administrator Portal\t\t\t\t|";
		cout << endl;
		cout << "\n---------------------------------------------------------------------------------------------------------------  \n";
		cout << "1) Add product" << endl;
		cout << endl;
		cout << "2) Modify product" << endl;
		cout << endl;
		cout << "3) Remove the product" << endl;
		cout << endl;
		cout << "4) List of items available" << endl;
		cout << endl;
		cout << "5) Back to menu" << endl;
		cin >> choice;
		switch (choice) {
		case 1: add();
			break;
		case 2: edit();
			break;
		case 3: rem();
			break;
		case 4: list();
			break;
		case 5: loop1 = 0;
			menu();
			break;
		default:
			cout << "Enter correct choice" << endl;

		}
	}

}


void shopping::buyer() {

	int choice;
	cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout << endl;
	cout << "|\t\t\t\tHope you have a good shopping experience\t\t\t\t|";
	cout << endl;
	cout << "\n---------------------------------------------------------------------------------------------------------------------  \n";
	cout << "1) Buy Product" << endl;
	cout << endl;
	cout << "2) Go back to the menu" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		reciept();
		break;
	case 2:
		menu();
		break;
	default:
		cout << "Please select the correct option" << endl;

	}
}


void shopping::add() {
	fstream data;
	int c;
	string n;
	double d, p;
	int choice, token = 0;
m:
	cout << "\n\t\t\t\t Enter new product" << endl;
	cout << " Enter the product code:";
	cin >> pcode;
	cout << "\n Enter the product Name:";
	cin >> pname;
	cout << "\n Enter the product price:";
	cin >> price;
	cout << "\n Enter the discount:";
	cin >> dis;


	data.open("database.txt", ios::in);
	if (data.is_open()) {
		do {
			data >> c >> n >> p >> d;
			if (pcode == c)
				token++;
		} while (!data.eof());
		data.close();
	}
	else data.open("database.txt", ios::app | ios::out);
	{
		data << pcode << " " << pname << " " << price << " " << dis << endl;
		data.close();
	}
		

	if (token == 1)
	{
		cout << "\t\t\t\t \\error------------------------------------------Product Already present-------------------------------------" << endl;
		goto m;
	}

	else
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
		data.close();
		cout << "\t\t\t\tProduct has been successfully added" << endl;
	}


}




void shopping::edit() {
	fstream data, data1;
	int token = 0;
	int tempkey;
	int c;
	string n;
	double d, p;

	cout << "\n\t\t\t\t Modify the Product " << endl;
	cout << "Enter the product code:";
	cin >> tempkey;

	data.open("database.txt", ios::in);
	if (data.is_open()) {
		data1.open("database1.txt", ios::out);

		data >> pcode >> pname >> price >> dis;
		while (!data.eof()) {
			if (tempkey == pcode) {
				cout << "Product new code:";
				cin >> c;
				cout << "\nProduct Name:";
				cin >> n;
				cout << "\nNew price:";
				cin >> p;
				cout << "\nNew discount:";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << endl;
				cout << "Record has been edited";
				token++;
			}
			else {
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
			}
			data >> pcode >> pname >> price >> dis;
		}

		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
			cout << "\n\t\t\tRecord not found" << endl;
	}
	else {
		cout << "\n\t\t\tError opening database file" << endl;
	}
}


void shopping::rem() {
	fstream data, data1;
	int token = 0;
	int tempkey;

	cout << "\n\t\t\t Remove product" << endl;
	cout << "Enter the Product code:" << endl;
	cin >> tempkey;
	data.open("database.txt", ios::in);
	if (data.is_open()) {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (data.eof()) {
			if (tempkey == pcode)
			{
				cout << "\n\t\t\tproduct successfully removed" << endl;
				token++;
			}
			else
				data1 << " " << pcode << " " << pname << " " << price << " " << dis;

		}data >> pcode >> pname >> price >> dis;
	}
	else cout << "File doesnt exist" << endl;
	data.close();
	data1.close();
	remove("database.txt");
	rename("database1.txt", "database.txt");
	if (token == 0)
		cout << "product not found" << endl;
}


void shopping::list() {
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
	cout << "Pro no. \t Name\t\t Price" << endl;
	cout << "\n\n---------------------------------------------------------------------------------------------------------------------\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof()) {
		cout << left << setw(15) << pcode << setw(20) << pname << setw(10) << price << endl;
		data >> pcode >> pname >> price >> dis;
	}
	data.close();

}


void shopping::reciept() {
	vector<int> code;
	int q1, choice, cd;
	vector<int> qnty;
	fstream data;
	double amount = 0.f, famount = 0.f;

	data.open("database.txt", ios::in);
	if (!data.is_open()) {
		cout << "Error opening database file." << endl;
		return;
	}

	// Display the list of products
	list();

	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "\n\t\t\tPlace  your Order" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;

	do {
		cout << "Enter Product Code:" << endl;
		cin >> cd;
		code.push_back(cd);
		cout << "Enter Quantity:" << endl;
		cin >> q1;
		qnty.push_back(q1);

		// Check for similar products
		for (int i = 0; i < code.size() - 1; i++) {
			if (code[i] == cd) {
				cout << "Similar product already exists" << endl;
				code.pop_back();
				qnty.pop_back();
				break;
			}
		}

		cout << "Press 1 to continue shopping, 0 to exit" << endl;
		cin >> choice;
	} while (choice == 1);

	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t RECIEPT" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Product No. \t Prodcut Name\t Quantity\t\tPrice\each\t   Amount\t    Amount after Discount" << endl;

	// Calculate and display receipt
	for (int i = 0; i < code.size(); i++) {
		data.clear(); // Clear any error flags
		data.seekg(0, ios::beg); // Move file pointer to the beginning

		data >> pcode >> pname >> price >> dis;
		while (!data.eof()) {
			if (pcode == code[i]) {
				amount = price * qnty[i];
				famount += amount - (dis);
				cout << left << setw(15) << pcode << setw(25) << pname << setw(20) << qnty[i] << setw(15) << price << setw(20) << amount << setw(25) << dis << endl;
			}
			data >> pcode >> pname >> price >> dis;
		}
	}
	data.close();

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Total:" << famount;
}