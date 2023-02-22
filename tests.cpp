#define CATCH_CONFIG_MAIN
#include "List.h"
#include "catch.hpp"

TEST_CASE("constructors") {
    SECTION("default") {
        List aList;
        REQUIRE(aList.mySize == 0);
        REQUIRE(aList.myFirst == nullptr);
        REQUIRE(aList.myLast == nullptr);
    }
}

TEST_CASE("Node constructors") {
    SECTION("default") {
        List::Node aNode;
        REQUIRE(aNode.myItem == Item());
        REQUIRE(aNode.myNext == nullptr);
    }

    SECTION("explicit-value") {
        List::Node n1(11, nullptr);
        REQUIRE(n1.myItem == 11);
        REQUIRE(n1.myNext == nullptr);

        List::Node *n3 = new List::Node(33, nullptr);
        List::Node n2(22, n3);
        REQUIRE(n2.myItem == 22);
        REQUIRE(n2.myNext == n3);
    }
}

TEST_CASE("getFirst/getLast on empty list") {
    List l;
    REQUIRE_THROWS_AS(l.getFirst(), underflow_error);
    REQUIRE_THROWS_AS(l.getLast(), underflow_error);
}

TEST_CASE("prepend") {
    List aList;
    aList.prepend(22);
    REQUIRE(aList.getSize() == 1);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast == aList.myFirst);
    REQUIRE(aList.getFirst() == 22);
    REQUIRE(aList.getLast() == 22);
    REQUIRE(aList.myFirst->myNext == nullptr);

    // prepend to a list containing 1 Item
    aList.prepend(11);
    REQUIRE(aList.getSize() == 2);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast != nullptr);
    REQUIRE(aList.myFirst != aList.myLast);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 22);
    REQUIRE(aList.myFirst->myNext != nullptr);
    REQUIRE(aList.myLast->myNext == nullptr);

    aList.prepend(0);
    REQUIRE(aList.getSize() == 3);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast != nullptr);
    REQUIRE(aList.getFirst() == 0);
    REQUIRE(aList.getLast() == 22);
    REQUIRE(aList.myFirst->myNext->myItem == 11);
    REQUIRE(aList.myLast->myNext == nullptr);
}

TEST_CASE("append") {
    List aList;
    aList.append(11);
    REQUIRE(aList.getSize() == 1);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast == aList.myFirst);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 11);
    REQUIRE(aList.myFirst->myNext == nullptr);

    // append to a list containing 1 Item
    aList.append(22);
    REQUIRE(aList.getSize() == 2);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast != nullptr);
    REQUIRE(aList.myFirst != aList.myLast);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 22);
    REQUIRE(aList.myFirst->myNext != nullptr);
    REQUIRE(aList.myLast->myNext == nullptr);
    REQUIRE(aList.myFirst->myNext == aList.myLast);

    aList.append(33);
    REQUIRE(aList.getSize() == 3);
    REQUIRE(aList.myFirst != nullptr);
    REQUIRE(aList.myLast != nullptr);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 33);
    REQUIRE(aList.myFirst->myNext->myItem == 22);
    REQUIRE(aList.myLast->myNext == nullptr);
}

TEST_CASE("destructor") {
    List l;
    l.prepend(33);
    l.prepend(22);
    l.prepend(11);
    l.~List();
    // Risky getting values from an already-freed object...
    REQUIRE(l.getSize() == 0);
    REQUIRE(l.myFirst == nullptr);
    REQUIRE(l.myLast == nullptr);

    // Tester should check for memory leaks... somehow...
}

TEST_CASE("writeTo") {
    List l0;
    l0.prepend(33);
    l0.prepend(22);
    l0.prepend(11);
    l0.writeTo(cout);
    cout << endl << "Check that output looks like this: 11 22 33" << endl;
}