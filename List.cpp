/*
 * List.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: vtn2
 */

#include "List.h"

#include <iostream>
#include <stdexcept>
using namespace std;

List::List() {
    mySize = 0;
    myFirst = myLast = nullptr;
}

List::~List() {
    mySize = 0;
    delete myFirst;
    myFirst = myLast = nullptr;
}

List::Node::Node() {
    myItem = Item();
    myNext = nullptr;
}

List::Node::Node(Item it, Node *next) {
    myItem = it;
    myNext = next;
}

List::Node::~Node() {
    // cout << "~Node() is deallocating the node containing item "
    //		<< myItem << endl;
    delete myNext;
    myNext = nullptr;
}

Item List::getFirst() const {
    if (mySize == 0) {
        throw underflow_error("list is empty");
    }
    return myFirst->myItem;
}

Item List::getLast() const {
    if (mySize == 0) {
        throw underflow_error("list is empty");
    }
    return myLast->myItem;
}

void List::prepend(const Item &it) {
    Node *newNode = new Node(it, myFirst);
    myFirst = newNode;
    if (mySize == 0) {
        myLast = newNode;
    }
    mySize++;
}

void List::writeTo(ostream &out) const {
    for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
        out << curr->myItem << " ";
    }
}

string List::toString() const {
    string res = "";
    for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
        res += to_string(curr->myItem) + " ";
    }
    return res;
}
