#include "doublylinkedlist.h"
#include <iostream>

using namespace std;

//Node//

Node::Node() : prev(nullptr), next(nullptr), data(0) {}
Node::Node(int data) : prev(nullptr), next(nullptr), data(data) {}

int Node::get_data() {
	return this->data;
}
Node* Node::get_prev() {
	return this->prev;
}
Node* Node::get_next() {
	return this->next;
}
void Node::set_data(int data) {
	this->data = data;
}
void Node::set_prev(Node* prev) {
	this->prev = prev;
}
void Node::set_next(Node* next) {
	this->next = next;
}

//Double Linked List//

Dlinklist::Dlinklist(Node* newNode, unsigned int size) : head(newNode), tail(newNode), size(size){}
//Dlinklist::Dlinklist(unsigned int size) : head(new Node()), tail(this->head), size(size) {}
Dlinklist::~Dlinklist() {


}

bool Dlinklist::add(Node* newNode, unsigned int pos) {
	bool sucess = true;

	if (pos < 0 || pos > this->size || newNode == nullptr) sucess = false;
	else {
		
		Node* nextNode = this->head;
		unsigned int i = 0;


		while (i <= pos) {

			if (nextNode->get_next() == nullptr) {
				nextNode->set_next(newNode);
				this->tail = newNode;
				this->tail->set_prev(nextNode);
				break;
			}
			else if (i == pos) {
				newNode->set_next(nextNode);
				newNode->set_prev(nextNode->get_prev());
				nextNode->get_prev()->set_next(newNode);
				nextNode->set_prev(newNode);
			}

			nextNode = nextNode->get_next();
			i++;
		 }



	}

	return sucess;
}
bool Dlinklist::remove(unsigned int pos) {
	Node* nextNode = this->head;
	unsigned int i = 0;
	bool sucess = true;

	if (pos < 0 || pos > this->size) sucess = false;
	else {
		
		while (nextNode != nullptr && i < pos) {
			i++;
			nextNode = nextNode->get_next();
		}

		nextNode->get_next()->set_prev(nextNode->get_prev());
		nextNode->get_prev()->set_next(nextNode->get_next());

	}

	return sucess;
}
bool Dlinklist::replace(Node* oldNode, Node* newNode) {
	bool sucess = true;

	if (oldNode == nullptr || newNode == nullptr) sucess = false;
	else {
		newNode->set_next(oldNode->get_next());
		newNode->set_prev(oldNode->get_prev());

		if (oldNode->get_next() != nullptr) oldNode->get_next()->set_prev(newNode);
		else this->tail = newNode;

		if (oldNode->get_prev() != nullptr) oldNode->get_prev()->set_next(newNode);
		else this->head = newNode;

		oldNode->set_next(nullptr);
		oldNode->set_prev(nullptr);

	}

	return sucess;
}
int Dlinklist::size_of() {
	
	Node* nextNode = this->head;
	int ret = 0;

	while (nextNode != nullptr) {
		ret++;
		nextNode = nextNode->get_next();
	}
	
	return ret;
}
int Dlinklist::search(Node* data) {
	Node* nextNode = this->head;
	int ret = -1;
	int i = 0;

	while (nextNode != nullptr) {
		if (nextNode == data) {
			ret = i;
			break;
		}

		i++;
		nextNode = nextNode->get_next();
	}

	return ret;
}
void Dlinklist::display_forward() {

	Node* nextNode = this->head;

	while (nextNode != nullptr) {
		cout << nextNode->get_data() << " ";
		nextNode = nextNode->get_next();
	}

	cout << endl;
}
void  Dlinklist::display_backward() {


	Node* nextNode = this->tail;

	while (nextNode != nullptr) {
		cout << nextNode->get_data() << " ";
		nextNode = nextNode->get_prev();
	}

	cout << endl;
}