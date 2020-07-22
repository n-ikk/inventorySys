#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class inventory_list {

public:
	inventory_list();
	void add();
	void remove();
	void printout();
	void search();
	void load();
	void save();
	void addEmptyFirstNode();
	void addEmptyNodeLast();

private:
	struct list_node {
		string name, miscInfo;
		int quantity;
		double buyPrice, sellPrice;
		list_node *next;
	};

	list_node *first, *prev, *current;


};




int main() {

	//Main serving as solely a driver for other functions to be included
	bool menu = true;
	int menuChoice;
	inventory_list inventory;
	
	cout << "Please wait for loading data" << endl;
	inventory.load();
	cout << "Inventory loaded" << endl;;



	while (menu == true) {
		cout << "What would you like to do: " << endl << "1. Add to inventory" << endl << "2. Remove from inventory" << endl << "3. Display inventory" << endl << "4. Search" << endl;
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			inventory.add();
			inventory.save();
			break;
		case 2:
			inventory.remove();
			inventory.save();
			break;
		case 3:
			inventory.printout();
			break;
		case 4:
			inventory.search();
			break;


		}
	}
}

inventory_list::inventory_list() {
	//dummy first node
	first = new list_node;
	first->next = 0;
	prev = first;

}

void inventory_list::add() {
	char continueLoop = 'Y';

	while (continueLoop == 'Y') {
		//adding node to list
		
		while (current->next != 0) {

		}

		prev = current;
		current = new list_node;
		prev->next = current;
	


		//manually enter data
		cout << "Enter the name: ";
		cin.ignore();
		getline(cin, current->name);
		cout << "Enter the buy price: ";
		cin >> current->buyPrice;
		cout << "Enter the sell price: ";
		cin >> current->sellPrice;
		cout << "Enter your quantity: ";
		cin >> current->quantity;
		cout << "Enter any misc. info: ";
		cin.ignore();
		getline(cin, current->miscInfo);

		//optional continued input
		cout << endl << "Any more products? [Y/N]";
		cin >> continueLoop;


	}
}

//DONE FUCNTION
//TODO TEST VALIDITY
void inventory_list::remove() {
	//Specified product to remove
	string removeTarget;
	
	cout << "Which product would you like to remove: ";
	cin >> removeTarget;

	current = first->next;

	while (current->name != removeTarget) {

		if (current->name == removeTarget) {
			prev->next = current->next;
			cout << current->name << " succesfully removed";
			delete current;
			return;
		}
		else if (current->next == 0) {
			cout << "Product not found";
			return;
		}



		current = current->next;
	}

//DONE FUNCTION
}void inventory_list::printout() {
	current = first->next;
	cout << "Name" << '\t' << "Buy Price" << '\t' << '\t' << "Sell Price" << '\t' << "Quantity" << endl;
	while (current != 0) {
		cout << current->name << '\t' << current->buyPrice << '\t' << current->sellPrice << '\t' << current->quantity << endl;
		current = current->next;
	}

	return;
}
//DONE FUNCTION
void inventory_list::search() {
	string searchTarget;
	cout << "What product would you like to find: ";
	cin >> searchTarget;


	current = first->next;
	cout << "Name" << '\t' << "Buy Price" << '\t' << '\t' << "Sell Price" << '\t' << "Quantity" << endl;
	while (current->name != searchTarget) {
		if (current == 0) {
			cout << "Product not found";
		}
		else if (current->name == searchTarget) {
			cout << current->name << '\t' << current->buyPrice << '\t' << '\t' << current->sellPrice << '\t' << current->quantity << endl;
		}
		
		current = current->next;

	}

}



void inventory_list::load() {
	//loading data to linked list from text file
	string line;

	//REMOVE THIS
	return;
	//REMOVE THIS

	ifstream inventoryData("inventoryData.txt", ios::in);
	if (!inventoryData) {
		cout << "Error in reading data file, call Nikk";
		Sleep(5000);
		return;
	}
	else {
		inventory_list::addEmptyFirstNode();


	}
	
	//Having to load several different attributes into each individual node of a linked list

	while (!inventoryData.eof()) {

		inventoryData >> current->name;
		inventoryData >> current->buyPrice;
		inventoryData >> current->sellPrice;
		inventoryData >> current->quantity;
		inventoryData >> current->miscInfo;


		current = new list_node;
		first->next = current;


	}


}




//DONE AND WORKING
void inventory_list::save() {
	ofstream inventoryData("inventoryData.txt", ios::out);

	current = first->next;

	while (current != 0) {
		inventoryData << current->name << endl;
		inventoryData << current->buyPrice << endl;
		inventoryData << current->sellPrice << endl;
		inventoryData << current->quantity << endl;
		inventoryData << current->miscInfo << endl;

		current = current->next;
	}

}


void inventory_list::addEmptyFirstNode() {
	current = first;

	prev = current;
	current = new list_node;
	prev->next = current;
	current->next = 0;

}

void inventory_list::addEmptyNodeLast() {

	current = first;

	//Finding last occupied node
	while (current->next != 0) {
		current = current->next;

	}

	prev = current;
	current = new list_node;
	prev->next = current;
	current->next = 0;

}