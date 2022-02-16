#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum relationship {LESS, GREATER, EQUAL};

class node {
public:
	int data; //stores the number entered
	int position; //stores the position the node is in
	node* next; //stores the memory address of the next node
};

class linked_list {
public:
	node* head; //stores the memory address of the first node
	node* tail; //stores the memory address of the nodes after the head node
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	~linked_list() {
		head = NULL;
		tail = NULL;
	}
	void add_node(int n) {
		node* tmp = new node();
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;

		}
	}
	void isFull() {
		int full = 10;
		linked_list start;
		start.head = head;
		while (head != NULL) {
			head = head->next;
			full--;
		}
		if (full > 0) {
			cout << "List is not full" << endl;
			cout << full << " links unused." << endl;
		}
		else {
			cout << "List is full" << endl;
		}
		head = start.head;
	}
	void printList() {
		linked_list start;
		start.head = head;
		while (head != NULL) {
			cout << head->data << " - Position : " << head->position << endl;
			head = head->next;
		}
		head = start.head;
	}
	void searchList() {
		bool found = false;
		linked_list start;
		start.head = head;
		int search;
		cin >> search;
		while (head != NULL) {
			if (head->data == search) {
				cout << "Found : " << head->data << " in pos " << head->position << endl;
				found = true;
			}
			head = head->next;
		}
		if (!found) {
			cout << "Not in list" << endl;
		}
		head = start.head;
	}
	void assignPosition() {
		linked_list start;
		start.head = head;
		int count = 1;
		while (head != NULL) {
			head->position = count;
			head = head->next;
			count++;
		}
		head = start.head;
	}
	void getLength() {
		linked_list start;
		int pos = NULL;
		start.head = head;
		while (head != NULL) {
			pos = head->position;
			head = head->next;
		}
		cout << "List is " << pos << " links." << endl;
		head = start.head;
	}
	void deleteItem() {
		bool found = false;
		linked_list start;
		linked_list previous;
		start.head = head;
		previous.head = head;
		int search;
		cin >> search;
		while (head != NULL) {
			if (head->data == search) {
				previous.head->next = head->next;
				head->data = NULL;
				head->next = NULL;
				head = previous.head;
				found = true;
			}
			previous.head = head;
			head = head->next;
		}
		if (!found) {
			cout << "Not in list" << endl;
		}
		head = start.head;
	}
	void compareTo() {
		relationship compare;
		int positionA;
		int positionB;
		cout << "Compare position : ";
		cin >> positionA;
		cout << " with position : ";
		cin >> positionB;
		linked_list start;
		start.head = head;
		while (head != NULL) {
			if (positionA == head->position) {
				positionA = head->data;
			}
			head = head->next;
		}
		head = start.head;
		start.head = head;
		while (head != NULL) {
			if (positionB == head->position) {
				positionB = head->data;
			}
			head = head->next;
		}
		head = start.head;
		if (positionA > positionB) {
			compare = GREATER;
			cout << positionA << " is greater than " << positionB << endl;
		}
		else if (positionA < positionB) {
			compare = LESS;
			cout << positionA << " is less than " << positionB << endl;
		}
		else if (positionA == positionB) {
			compare = EQUAL;
			cout << positionA << " and " << positionB << " are equal" << endl;
		}
		else
			cout << "invalid" << endl;
	}
};

void unionSet(linked_list first , linked_list second) {
	linked_list unionedList;
	linked_list start;
	start.head = first.head;
	while (first.head != NULL) {
		
		first.head = first.head->next;
		unionedList.head = first.head;
	}
	unionedList.head->next = second.head;
	while (second.head != NULL) {
		
		second.head = second.head->next;
		unionedList.head = second.head;
	}
	unionedList.head = start.head;
	while (unionedList.head != NULL) {
		cout << unionedList.head->data << endl;
		unionedList.head = unionedList.head->next;
	}
}

int main() {
	const int max = 10;
	bool con = true;

	cout << "Fill first list :" << endl;
	linked_list unsortedListOne;
	while (con == true) {
		int x;
		int static listSize = 0;
		if (listSize != max){
			cin >> x;
			if (x == -1) {
				con = false;
				break;
			}
			unsortedListOne.add_node(x);
			listSize++;
		}
		else {
			con = false;
			break;
		}
	}
	cout << "Assigning position" << endl;
	unsortedListOne.assignPosition();
	cout << "Printing list :" << endl;
	unsortedListOne.printList();
	unsortedListOne.isFull();
	unsortedListOne.getLength();
	cout << "Enter something to search :" << endl;
	unsortedListOne.searchList();
	cout << "Compare data inputs" << endl;
	//unsortedListOne.compareTo();
	cout << "Delete something" << endl;
	unsortedListOne.deleteItem();
	unsortedListOne.assignPosition();
	cout << "Printing list" << endl;
	unsortedListOne.printList();
	cout << "Deleting list" << endl;
 	unsortedListOne.~linked_list();
	cout << "Printing list again:" << endl;
	unsortedListOne.printList();
	
	cout << "Fill second list :" << endl;
	con = true;
	linked_list unsortedListTwo;
	while (con == true) {
		int x;
		int static listSize = 0;
		if (listSize != max) {
			cin >> x;
			if (x == -1) {
				con = false;
				break;
			}
			unsortedListTwo.add_node(x);
			listSize++;
		}
		else {
			con = false;
			break;
		}
	}
	cout << "Performing union set operation" << endl;
	unionSet(unsortedListOne, unsortedListTwo);

	return 0;
}