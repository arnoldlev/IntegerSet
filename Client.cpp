// Arnold Lev
// CSIS 137 (Online)
// Homework #2


#include "IntegerSet.h"
#include <iostream>
using namespace std;

int main() {
	int grade[6];
	grade[0] = 0;
	grade[1] = 1;
	grade[2] = 3;
	grade[4] = 5;

	IntegerSet intset(5);
	IntegerSet intset2(5);
	IntegerSet intset3(grade, 6);


	cout << "Set #1: ";  intset.printSet(); cout << "SIZE: " << intset.getSize() << endl << endl;
	cout << "Set #2: ";  intset2.printSet(); cout << "SIZE: " << intset2.getSize() << endl << endl;
	cout << "Set #3: ";  intset3.printSet(); cout << "SIZE: " << intset3.getSize() << endl << endl;

	cout << "------- [ CHANGING VALUES ] -------" << endl;

	intset.insertElement(3);
	intset.insertElement(4);

	intset2.insertElement(4);
	intset2.insertElement(2);


	IntegerSet* intset4 = intset.unionOfSets(intset2);
	IntegerSet* intset5 = intset.intersectionOfSets(intset2);

	cout << "Set #1: ";  intset.printSet(); cout << "SIZE: " << intset.getSize() << endl << endl;
	cout << "Set #2: ";  intset2.printSet(); cout << "SIZE: " << intset2.getSize() << endl << endl;
	cout << "Set #4: ";  intset4->printSet(); cout << "SIZE: " << intset4->getSize() << endl << endl;
	cout << "Set #5: ";  intset5->printSet(); cout << "SIZE: " << intset5->getSize() << endl << endl;

	cout << "Are the intset and inset2 equal? " << intset.isEqual(intset2) << endl;

	cout << "------- [ CHANGING VALUES ] -------" << endl;

	intset2.deleteElement(2);

	cout << "Set #2: ";  intset2.printSet(); cout << "SIZE: " << intset2.getSize() << endl << endl;

	return 0;
}