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
#include <utility>  // pair

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

// my test
TEST(CollatzFixture, read_2) {
    istringstream r("1001 2000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1001, i);
    ASSERT_EQ(2000, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("110000 100000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(110000, i);
    ASSERT_EQ(100000, j);}

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

// my tests
TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1001, 2000);
    ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(38923, 40857);
    ASSERT_EQ(306, v);
}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(110000, 100000);
    ASSERT_EQ(354, v);
}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(999999, 998999);
    ASSERT_EQ(396, v);
}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_length_1) {
    const int v = cycle_length(1);
    ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_2) {
    const int v = cycle_length(22);
    ASSERT_EQ(16, v);
}

TEST(CollatzFixture, cycle_length_3) {
    const int v = cycle_length(38485);
    ASSERT_EQ(63, v);
}

TEST(CollatzFixture, cycle_length_4) {
    const int v = cycle_length(110000);
    ASSERT_EQ(93, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 38923, 40857, 306);
    ASSERT_EQ("38923 40857 306\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
