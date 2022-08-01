/*
 * List.h
 *
 *  Created on: Feb 21, 2022
 *      Author: vtn2
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

typedef double Item;

class List {
   public:
    List();
    virtual ~List();
    unsigned getSize() const { return mySize; }
    Item getFirst() const;
    Item getLast() const;
    void prepend(const Item &it);
    void writeTo(ostream &out) const;

    /* I am making all the internal details available publicly,
       for testing. Everything below here should be private. */
   public:
    struct Node {
        Node();
        Node(Item it, Node *next);
        virtual ~Node();
        Item myItem;
        Node *myNext;
    };
    unsigned mySize;
    Node *myFirst;
    Node *myLast;
};

#endif /* LIST_H_ */
