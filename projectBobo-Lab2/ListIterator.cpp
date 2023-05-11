#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list), currentNode(list.head) {
	//TODO - Implementation
}

void ListIterator::first() {
	//TODO - Implementation
    this->currentNode = list.head;
}

void ListIterator::next() {
	//TODO - Implementation
    if(this->valid())
        this->currentNode = this->currentNode->next;
    else
        throw std::exception();
}

bool ListIterator::valid() const {
	//TODO - Implementation
	return this->currentNode != nullptr;
}

TElem ListIterator::getCurrent() const {
	//TODO - Implementation
    if(!valid())
        throw std::exception();
	return this->currentNode->info;
    //return NULL_TELEM;
}

DLLNode *ListIterator::getCurrentNode() const {
    return this->currentNode;
}



