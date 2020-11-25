// Arnold Lev
// CSIS 137 (Online)
// Homework #2

#include "IntegerSet.h"
#include <iostream>
using namespace std;

IntegerSet::IntegerSet(int length) {
	set = new int[length] ();
	size = length;
}

IntegerSet::IntegerSet(int* arr, int length) {
	set = new int[length] ();
	for (int i = 0; i < length; i++) {
		if (arr[i] < length && arr[i] >= 0) {
			set[arr[i]] = 1;
		}
	}
	size = length;
}

IntegerSet::~IntegerSet() {
	delete[] set;
}

IntegerSet* IntegerSet::unionOfSets(const IntegerSet& set2) {
	IntegerSet* set3 = new IntegerSet(getSize() + set2.getSize());
	for (int i = 0; i < getSize(); i++) {
		if (set[i] == 1)
			set3->insertElement(i);
	}
	for (int i = 0; i < set2.getSize(); i++) {
		if (set2.getSet()[i] == 1)
			set3->insertElement(i);
	}
	return set3;
}

IntegerSet* IntegerSet::intersectionOfSets(const IntegerSet& set2) {
	IntegerSet* set3 = new IntegerSet(getSize() + set2.getSize());
	for (int i = 0; i < set3->getSize(); i++) {
		if (set[i] == 1 && set2.getSet()[i] == 1) {
			set3->insertElement(i);
		}
	}
	return set3;
}

bool IntegerSet::insertElement(int num) {
	if (num < getSize()) {
		set[num] = 1;
		return true;
	}
	return false;
}

bool IntegerSet::deleteElement(int num) {
	if (num < getSize()) {
		set[num] = 0;
		return true;
	}
	return false;
}

void IntegerSet::printSet() const {
	if (isEmpty()) {
		cout << "----" << endl;
	} else {
		for (int i = 0; i < size; i++) {
			if (set[i] == 1) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
}

bool IntegerSet::isEqual(const IntegerSet& set2) {
	if (getSize() != set2.getSize()) {
		return false;
	} else {
		for (int i = 0; i < size; i++) {
			if (set[i] != set2.getSet()[i]) {
				return false;
			}
		}
	}
	return true;
}

bool IntegerSet::isEmpty() const {
	int empty = 0;
	for (int i = 0; i < size; i++) {
		if (set[i] == 0) {
			empty++;
		}
	}
	return empty == size;
}

int IntegerSet::getSize() const {
	return size;
}

int* IntegerSet::getSet() const {
	return set;
}

