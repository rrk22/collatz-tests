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
    const int v = collatz_eval(1000, 1999);
    ASSERT_EQ(182, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1001, 3000);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(5000, 10000);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(300, 333);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(3, 3);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(5, 5);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(100000, 150000);
    ASSERT_EQ(375, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(300000, 400000);
    ASSERT_EQ(441, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(799999, 999999);
    ASSERT_EQ(525, v);}

TEST(CollatzFixture, eval_14) {
    const int v = collatz_eval(55000, 120000);
    ASSERT_EQ(354, v);}

TEST(CollatzFixture, eval_15) {
    const int v = collatz_eval(500000, 599999);
    ASSERT_EQ(470, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 5, 5, 6);
    ASSERT_EQ("5 5 6\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("2 2\n4 4\n8 8\n16 16\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("2 2 2\n4 4 3\n8 8 4\n16 16 5\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("99 999\n1000 10000\n9999 99999\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("99 999 179\n1000 10000 262\n9999 99999 351\n", w.str());}
