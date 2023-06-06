#include <iostream>
#include "Set.h"
#include "SetIterator.h"

Set::Set() {
    // Initialize the hashtable and slots
    hashtable.resize(10, Node(NULL_TELEM, -1));
    slots.resize(10, -1);  // Initialize all slots as empty (-1)
    size_ = 0;
}

bool Set::add(TElem elem) {
    // Compute the hash value of the element
    int hash = hashFunction(elem);

    // Check if the element already exists in the set
    if (search(elem))
        return false;

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
        hashtable[index].next = hashtable.size();
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

    // Find the node to remove
    int slot = hash;
    int index = slots[slot];
    int prevIndex = -1;
    while (index != -1 && hashtable[index].element != elem) {
        prevIndex = index;
        index = hashtable[index].next;
    }

    // Remove the node from the hashtable and update the slots
    if (prevIndex == -1) {
        slots[slot] = hashtable[index].next;
    } else {
        hashtable[prevIndex].next = hashtable[index].next;
    }

    // If the removed node is not the last node, update the next pointers
    if (index != size_ - 1) {
        int lastIndex = size_ - 1;
        int lastSlot = hashFunction(hashtable[lastIndex].element);

        // Find the previous node of the last node
        int prevLastIndex = -1;
        int currIndex = slots[lastSlot];
        while (currIndex != lastIndex) {
            prevLastIndex = currIndex;
            currIndex = hashtable[currIndex].next;
        }

        // Update the next pointer of the previous node
        if (prevLastIndex == -1) {
            slots[lastSlot] = index;
        } else {
            hashtable[prevLastIndex].next = index;
        }

        // Update the next pointer of the removed node
        hashtable[index].next = hashtable[lastIndex].next;

        // Copy the last node to the removed node's position
        hashtable[index].element = hashtable[lastIndex].element;

        // Update the next pointer of the node that was swapped with the removed node
        if (hashtable[index].next != -1) {
            int nextIndex = hashtable[index].next;
            hashtable[nextIndex].next = index;
        }
    }

    // Decrease the size
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
