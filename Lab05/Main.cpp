#include "Node.h"
#include <iostream>
using namespace std; 

int main(int argc, char* argv[]) {
cout << "Constructing empty node" << endl;
Node node1;
cout << node1 << endl;

cout << "Constructing node2 with Element e" << endl;
Element e = 1.1;
Node node2(e);
cout << node2 << endl;

cout << "Pointing node2 to node1" << endl;
node2.setNext(node1);
cout << node2;

cout << "Setting node1 = node2" << endl;
Node node6(node1);

cout << "Final status of node1 and 2" << endl;
cout << node1 << endl;
cout << node2 << endl;

}
