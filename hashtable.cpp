#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {

	//*****************************
	// implement constructor here *
	//*****************************
	this->size = size;
	hashTable = new vector<int>;
	hashTable->resize(size);
	for (int i = 0; i < size; i++)
	{
		hashTable->at(i) = -1;
	}

	collisionCount = 0;
	elements = 0;
}

HashTable::~HashTable()
{
	//****************************
	// implement destructor here *
	//****************************
	delete hashTable;
}

int HashTable::hashValue(int item) {

	int index = -1; //dummy initializtation

	//******************************************
	// implement calculation of hashindex here *
	//******************************************
	int _i = 0;
	while (true) {
		index = (item + _i * _i) % size;
		if (hashTable->at(index) == -1)
		{
			break;
		}
		else
		{
			collisionCount++;
			_i++;
		}
	}
	return index;
}

int HashTable::insert(int item) {

	//******************************************
	// implement insertion of new element here *
	//******************************************
	int hash = hashValue(item);
	hashTable->at(hash) = item;
	elements++;
	return 0; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
