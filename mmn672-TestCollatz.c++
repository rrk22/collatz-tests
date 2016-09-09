// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}
//Test if bounds are equal
TEST(CollatzFixture, equal_bounds) {
    const int v = collatz_eval(10,10);
    ASSERT_EQ(7, v);
}
//Max is lower bound
TEST(CollatzFixture, max_lower) {
    const int v = collatz_eval(9, 11);
    ASSERT_EQ(20, v);
}
//Max is upper bound
TEST(CollatzFixture, max_upper) {
    const int v = collatz_eval(9, 18);
    ASSERT_EQ(21, v);
}
//Test swap
TEST(CollatzFixture, swap) {
    const int v = collatz_eval(200, 100);
    ASSERT_EQ(125, v);
}
//Test highest numbers
TEST(CollatzFixture, highest_num) {
    const int v = collatz_eval(999999, 999168);
    ASSERT_EQ(396, v);
}
//Test a larger interval
TEST(CollatzFixture, larger_than_interval) {
    const int v = collatz_eval(823782, 822140);
    ASSERT_EQ(375, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 123, 456, 789);
    ASSERT_EQ("123 456 789\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("999999 999999\n782336 785917\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("999999 999999 259\n782336 785917 375\n", w.str());
}
