#include <iostream>
#include "Set.h"
#include "SetIterator.h"

Set::Set() {
    // Initialize the hashtable and slots
    hashtable.resize(5000, Node(NULL_TELEM, -1));
    slots.resize(5000, -1);  // Initialize all slots as empty (-1)
    size_ = 0;
}

bool Set::add(TElem elem) {
    // Check if the element already exists in the set
    if (search(elem))
        return false;

    // Compute the hash value of the element
    int hash = hashFunction(elem);

    // Create a new node with the element
    Node newNode(elem, -1);

    // Insert the new node into the hashtable
    int slot = hash;
    if (slots[slot] == -1) {
        slots[slot] = hashtable.size();
    } else {
        int index = slots[slot];
        while (hashtable[index].next != -1)
            index = hashtable[index].next;
        newNode.next = hashtable.size();
        hashtable[index].next = newNode.next;
    }

    // Add the node to the hashtable and increment the size
    hashtable.push_back(newNode);
    size_++;

    return true;
}


bool Set::remove(TElem elem) {
    // Compute the hash value of the element
    int hash = hashFunction(elem);

    // Check if the element exists in the set
    if (!search(elem))
        return false;

    // Find the slot in the hash table
    int slot = hash;
    int prevIndex = -1;
    int currIndex = slots[slot];

    // Traverse the linked list to find the node to remove
    while (currIndex != -1 && hashtable[currIndex].element != elem) {
        prevIndex = currIndex;
        currIndex = hashtable[currIndex].next;
    }

    // Remove the node from the linked list
    if (prevIndex == -1) {
        slots[slot] = hashtable[currIndex].next;
    } else {
        hashtable[prevIndex].next = hashtable[currIndex].next;
    }

    // Mark the removed node as deleted
    hashtable[currIndex].element = NULL_TELEM;
    hashtable[currIndex].next = -1;

    // Update the size
    size_--;

    return true;
}





bool Set::search(TElem elem) const {
    // Compute the hash value of the element
    int hash = hashFunction(elem);

    // Search for the element in the set
    int slot = hash;
    int index = slots[slot];
    while (index != -1) {
        if (hashtable[index].element == elem)
            return true;
        index = hashtable[index].next;
    }

    return false;
}


int Set::size() const {
    return size_;
}

bool Set::isEmpty() const {
    return size_ == 0;
}

SetIterator Set::iterator() const {
    return SetIterator(*this);
}

Set::~Set() {
    // No dynamic memory allocation to deallocate
}
