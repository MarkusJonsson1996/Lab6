#include "SDL.h"
#include "doublylinkedlist.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	Node n1(1);
	Node n2(25);
	Node n3(50);
	Node n4(100);
	Node n5(200);

	Dlinklist dl(&n1, 4);
	
	cout << dl.add(&n3, 1) << endl;
	cout << dl.add(&n4, 3) << endl;
	cout << dl.add(&n2, 1) << endl;
	cout << dl.add(&n5, 7) << endl;
	cout << dl.add(nullptr, 1) << endl;
	cout << dl.size_of() << endl; 

	cout << "-------------" << endl;

	dl.display_forward();
	dl.remove(1);
	dl.replace(&n4, &n5);
	dl.display_backward();

	cout << dl.node_at(1)->get_data() << endl;
	cout << "-------------" << endl;
	cout << dl.search(&n5) << endl;
	cout << dl.search(&n2) << endl;
	cout << dl.search(&n4) << endl;
	cout << "-------------" << endl;
	cout << dl.size_of();

	

	return 0;
}