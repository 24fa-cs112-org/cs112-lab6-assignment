#define CATCH_CONFIG_MAIN
#include "List.h"
#include "catch.hpp"

TEST_CASE("constructors") {
    SECTION("default") {
        List aList;
        REQUIRE(aList.getSize() == 0);
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
    REQUIRE(aList.getFirst() == 22);
    REQUIRE(aList.getLast() == 22);

    // prepend to a list containing 1 Item
    aList.prepend(11);
    REQUIRE(aList.getSize() == 2);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 22);

    aList.prepend(0);
    REQUIRE(aList.getSize() == 3);
    REQUIRE(aList.getFirst() == 0);
    REQUIRE(aList.getLast() == 22);

    // tests to make sure everything is linked up correctly.
    REQUIRE(aList.toString() == "0 11 22 ");
}

TEST_CASE("append") {
    List aList;
    aList.append(11);
    REQUIRE(aList.getSize() == 1);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 11);

    // append to a list containing 1 Item
    aList.append(22);
    REQUIRE(aList.getSize() == 2);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 22);

    aList.append(33);
    REQUIRE(aList.getSize() == 3);
    REQUIRE(aList.getFirst() == 11);
    REQUIRE(aList.getLast() == 33);

    REQUIRE(aList.toString() == "11 22 33 ");
}

TEST_CASE("destructor") {
    List l;
    l.prepend(33);
    l.prepend(22);
    l.prepend(11);
    l.~List();
    // Risky getting values from an already-freed object...
    REQUIRE(l.getSize() == 0);
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

TEST_CASE("toString") {
    List l0;
    l0.prepend(33);
    l0.prepend(22);
    l0.prepend(11);
    l0.writeTo(cout);
    REQUIRE(l0.toString() == "11 22 33 ");
}
