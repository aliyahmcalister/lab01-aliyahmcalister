// intlist.cpp
// Implements class IntList
// Aliyah McAlister, 1/13/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT deep copy
    if (source.head == nullptr) {
        return;
    }
    else {
        head = new Node;
        head->info = source.head->info;
    }
    Node* currentSource = source.head->next;
    Node* currentDest = head;
    while (currentSource != nullptr) {
        Node* newNode = new Node;
        newNode->info = currentSource->info;
        currentDest->next = newNode;
        currentDest = newNode;
        currentSource = currentSource->next;
    }
    currentDest->next = nullptr;
}
 
// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENTED
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0; 
    Node* head = this->head;
    while (head != nullptr) {
        sum += head->info;
        head = head->next;
    }
    return sum; // REPLACED THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node* current = head;
    if (current == nullptr) {
        return 0;
    }
    max = current->info;
    while (current != nullptr) {
        if (current->info > max) {
            max = current->info;
        }
        current = current->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int sum = this->sum();
    int numItems = 0;
    if (head == nullptr) {
        return 0.0;
    }
    Node* current = head;
    while (current != nullptr) {
        numItems++;
        current = current->next;
    }
    return double(sum)/numItems; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* newNode = new Node;
    newNode->info = value; // causing segmentation fault
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   int count = 0;
   Node* current = head;
    while (current != nullptr) {
       count++;
       current = current->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENTED
    if (this == &source) {
        return *this;
    }
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = source.head;
    tail = source.tail;
    if (source.head == nullptr) {
        return *this;
    }
    else {
        head = new Node;
        head->info = source.head->info;
    }
    Node* currentSource = source.head->next;
    Node* currentDest = head;
    while (currentSource != nullptr) {
        Node* newNode = new Node;
        newNode->info = currentSource->info;
        currentDest->next = newNode;
        currentDest = newNode;
        currentSource = currentSource->next;
    }
    currentDest->next = nullptr;
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENTED
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

