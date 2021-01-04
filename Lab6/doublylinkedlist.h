#pragma once

class Node {
public:

	Node();
	Node(int data);

	int get_data();
	Node* get_next();
	Node* get_prev();

	void set_data(int data);
	void set_prev(Node* prev);
	void set_next(Node* next);


private: 
	int data;
	Node* prev;
	Node* next;
};

class Dlinklist {
public:

	Dlinklist(Node* newNode, unsigned int size);
	//Dlinklist(unsigned int size);
	~Dlinklist();

	bool add(Node* newNode, unsigned int pos);
	bool remove(unsigned int pos);
	bool replace(Node* oldNode, Node* newNode);
	int search(Node* data);
	Node* node_at(unsigned int pos);
	void display_forward();
	void display_backward();
	int size_of();


private:

	unsigned int size;
	Node* head;
	Node* tail;
};

