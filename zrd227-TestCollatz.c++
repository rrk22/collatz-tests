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
    istringstream r("10000 156842\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 10000, i);
    ASSERT_EQ(156842, j);}

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

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(2000, 3100);
    ASSERT_EQ(217, v);
}

// ------
// length
// ------

TEST(CollatzFixture, length_1) {
    const int v = collatz_length(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, length_2) {
    const int v = collatz_length(79);
    ASSERT_EQ(36, v);}

TEST(CollatzFixture, length_3) {
    const int v = collatz_length(10385);
    ASSERT_EQ(87, v);}

TEST(CollatzFixture, length_4) {
    const int v = collatz_length(99999);
    ASSERT_EQ(227, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 267620, 35871, 2);
    ASSERT_EQ("267620 35871 2\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("1888 1860\n505 545\n3283 3541\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1888 1860 175\n505 545 137\n3283 3541 181\n", w.str());}
