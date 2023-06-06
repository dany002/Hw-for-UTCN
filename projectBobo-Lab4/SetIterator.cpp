#include "SetIterator.h"
#include "Set.h"

SetIterator::SetIterator(const Set& m) : set(m) {
    // Initialize the iterator to the first element (if any)
    first();
}

void SetIterator::first() {
    // Find the first non-empty slot in the set
    int slot = 0;
    while (slot < set.slots.size() && set.slots[slot] == -1) {
        slot++;
    }

    // Set the iterator to the first element in the slot (if any)
    if (slot < set.slots.size()) {
        currentSlot = slot;
        currentIndex = set.slots[slot];
    } else {
        // No elements in the set
        currentIndex = -1;
    }
}

void SetIterator::next() {
    // Move to the next element in the set (if any)
    if (valid()) {
        // If there is a next element in the current slot, move to it
        if (set.hashtable[currentIndex].next != -1) {
            currentIndex = set.hashtable[currentIndex].next;
        } else {
            // Otherwise, move to the next non-empty slot (if any)
            int nextSlot = currentSlot + 1;
            while (nextSlot < set.slots.size() && set.slots[nextSlot] == -1) {
                nextSlot++;
            }

            // Set the iterator to the next element in the next slot (if any)
            if (nextSlot < set.slots.size()) {
                currentSlot = nextSlot;
                currentIndex = set.slots[nextSlot];
            } else {
                // No more elements in the set
                currentIndex = -1;
            }
        }
    }
}

TElem SetIterator::getCurrent() {
    // Return the current element
    if (valid()) {
        return set.hashtable[currentIndex].element;
    } else {
        return NULL_TELEM;
    }
}

bool SetIterator::valid() const {
    // Check if the iterator is valid (i.e., pointing to a valid element)
    return currentIndex != -1;
}
