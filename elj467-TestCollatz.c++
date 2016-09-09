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

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("999998 999999");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(999998, i);
    ASSERT_EQ(999999, j);}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_1) {
    const int c = cycle_length(22, 0);
    ASSERT_EQ(16, c);
}

TEST(CollatzFixture, cycle_2) {
    const int c = cycle_length(5, 0);
    ASSERT_EQ(6, c);
}

TEST(CollatzFixture, cycle_3) {
    const int c = cycle_length(10, 0);
    ASSERT_EQ(7, c);
}

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

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 201, 210, 89);
    ASSERT_EQ("201 210 89\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("80808 999191\n134955 923\n239495 2345\n69456 234593\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("80808 999191 525\n134955 923 354\n239495 2345 443\n69456 234593 443\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("89213 18924\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("89213 18924 351\n", w.str());}

