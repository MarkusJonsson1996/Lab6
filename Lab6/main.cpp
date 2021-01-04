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

	dl.add(&n3, 1);
	dl.add(&n4, 3);
	dl.add(&n2, 1);

	cout << dl.search(&n5);

	

	return 0;
}