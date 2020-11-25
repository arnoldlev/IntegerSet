// Arnold Lev
// CSIS 137 (Online)
// Homework #2

#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet {
	private:
		int* set;
		int size;
		bool isEmpty() const;
		int* getSet() const;
	public:
		IntegerSet(int);
		IntegerSet(int*, int);
		~IntegerSet();
		bool insertElement(int);
		bool deleteElement(int);
		bool isEqual(const IntegerSet&);
		IntegerSet* unionOfSets(const IntegerSet&);
		IntegerSet* intersectionOfSets(const IntegerSet&);
		void printSet() const;
		int getSize() const;
};


#endif