
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

DLLNode::DLLNode(TElem info) {
    this->info = info;
    this->next = NULL;
    this->prev = NULL;
}



IteratedList::IteratedList() {
	//TODO - Implementation
    this->current_size = 0;
    this->head = NULL;
    this->tail = NULL;
}

int IteratedList::size() const {
	//TODO - Implementation
	return this->current_size;
}

bool IteratedList::isEmpty() const {
	//TODO -  Implementation
	return this->current_size == 0;
}

ListIterator IteratedList::first() const {
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
	//TODO - Implementation
    if(!pos.valid())
        throw std::exception();
    return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator& pos) {
	//TODO - Implementation
    if (!pos.valid())
        throw std::exception();

    DLLNode* nodeToRemove = pos.getCurrentNode();
    TElem removedElement = nodeToRemove->info;

    if (nodeToRemove == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
    } else if (nodeToRemove == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    delete nodeToRemove;
    current_size--;

    pos.next();
    return removedElement;

}

ListIterator IteratedList::search(TElem e) const{
	//TODO - Implementation
    ListIterator it(*this);
    it.first();
    while(it.valid()){
        if(it.getCurrent() == e)
            return it;
        it.next();
    }
	return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    //TODO - Implementation
    if(!pos.valid())
        throw std::exception();
    TElem old = pos.getCurrent();
    pos.getCurrentNode()->info = e;
    return old;

}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    //TODO - Implementation
    if (!pos.valid())
        throw std::exception();

    if (pos.getCurrentNode() == tail) {
        addToEnd(e);
        pos.next();
    } else {
        DLLNode* newNode = new DLLNode(e);
        newNode->next = pos.getCurrentNode()->next;
        newNode->prev = pos.getCurrentNode();
        pos.getCurrentNode()->next->prev = newNode;
        pos.getCurrentNode()->next = newNode;
        current_size++;
        pos.next();
    }
}

void IteratedList::addToEnd(TElem e) {
	//TODO - Implementation
    DLLNode* newNode = new DLLNode(e);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    current_size++;
}

IteratedList::~IteratedList() {
	//TODO - Implementation
    DLLNode* current = head;
    while (current != nullptr) {
        DLLNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void IteratedList::addToBeginning(TElem e) {
    DLLNode* newNode = new DLLNode(e);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    current_size++;
}

