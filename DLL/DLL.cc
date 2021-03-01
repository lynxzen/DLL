#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* prev;
	Node* next;
public:
	Node(int new_data = 0, Node* new_prev = nullptr, Node* new_next = nullptr) { //A construtor that has 1, 2, or 3 parameters
		data = new_data;
		prev = new_prev;
		next = new_next;
	}
	void set_data(int new_data) { data = new_data; }
	void set_prev(Node* new_prev) { prev = new_prev; }
	void set_next(Node* new_next) { next = new_next; }
	int get_data() { return data; }
	Node* get_prev() { return prev; }
	Node* get_next() { return next; }
};

class LL {
private:
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	int get_size();
	void append(int x);
	void prepend(int x);
	void deleteNode(int x);
	void deleteIndex(int x);
	void print();
};

int LL::get_size() { return size; }

void LL::append(int x) {
	Node* temp = new Node(x);
	if (tail == nullptr) {
		head = tail = temp;
	}
	else {
		/* This didn't work for deletion, but why?
		temp->set_prev(tail); //Set temp's previous to the old tail
		tail->set_next(temp); //Set the old tail's next to temp
		tail = temp;		  //Make the temp the new tail
		*/
		tail->set_next(temp);
		temp->set_prev(tail);
		tail = temp;
	}
	size++;
}

void LL::prepend(int x) {		//Adds node to the beginning of the list
	Node* temp = new Node(x);	//Temporary node containing the new user-inputted data
	if (head == nullptr) {		//If the list is empty, create a new node that is head and tail
		head = tail = temp;
	}
	else {
		head->set_prev(temp); //If list is not empty, set the head's previous to temp 
		temp->set_next(head); //Set temp's next to the old head
		head = temp;		  //Set the head to temp, as it now the new head
		/*
		temp->set_prev(nullptr);
		temp->set_next(head);
		head = temp;
		*/
	}
	size++;
}

void LL::deleteNode(int x) {
	if (x == head->get_data()) {
		Node* temp = head;
		head = head->get_next();
		delete temp;
		head->set_prev(nullptr);
	}
	if (x == tail->get_data()) {
		Node* temp = tail;
		tail = tail->get_prev();
		delete temp;
		tail->set_next(nullptr);
	}
	else {
		Node* temp = head;
		while (temp) {
			if (x == temp->get_data()) {
				temp->get_prev()->set_next(temp->get_next());
				temp->get_next()->set_prev(temp->get_prev());
				delete temp;
				break;
			}
			else {
				temp = temp->get_next();
			}
		}
	}
	size--;
}

void LL::deleteIndex(int x) {
	Node* temp = head;
	for (int i = 1; i < x; i++) {
		temp = temp->get_next();
		cerr << "getting next.." << endl;
	}
	if (temp == head && temp == tail) {
		delete temp;
		return;
	}
	if (temp == head) {
		head = head->get_next();
		delete temp;
		head->set_prev(nullptr);
		return;
	}
	if (temp == tail) {
		tail = tail->get_prev();
		delete temp;
		tail->set_next(nullptr);
		return;
	}
	else {
		temp->get_prev()->set_next(temp->get_next());
		temp->get_next()->set_prev(temp->get_prev());
		delete temp;
		return;
	}
}

void LL::print() {
	Node* temp = head;
	int i = 1;
	while (temp) {
		cout << "Node " << i << ": " << temp->get_data() << endl;
		temp = temp->get_next();
		i++;
	}
}

int main() {
	LL list;
	int choice = 0, x = 0;

	while (true) {

		cout << "1) Append 2) Prepend 3) Delete Node 4) Delete Index 5) Print 6) Quit" << endl;
		cin >> choice;

		if (choice == 1) {
			cin >> x;
			list.append(x);
		}
		if (choice == 2) {
			cin >> x;
			list.prepend(x);
		}
		if (choice == 3) {
			cin >> x;
			list.deleteNode(x);
		}
		if (choice == 4) {
			cin >> x;
			list.deleteIndex(x);
		}
		if (choice == 5) {
			list.print();
		}
		if (choice == 6) {
			break;
		}
	}
}


/*
				cerr << "temp->get_data(): " << temp->get_data() << endl;
				cerr << "temp->get_prev(): " << temp->get_prev()->get_data() << endl;
				cerr << "temp->get_next(): " << temp->get_next() << endl;

				cerr << "LINE 1 RAN" << endl;

				cerr << "LINE 2 RAN" << endl;
				cerr << "temp->get_next(): " << temp->get_next() << endl;
				cerr << "temp->get_prev(): " << temp->get_prev() << endl;
*/
