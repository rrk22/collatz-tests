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
	
TEST(CollatzFixture, read_2) {
    istringstream r("363 1023\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 363, i);
    ASSERT_EQ(1023, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("122222 500000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 122222, i);
    ASSERT_EQ(500000, j);}
	
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
    const int v = collatz_eval(2323, 12637);
    ASSERT_EQ(268, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(30000, 60000);
    ASSERT_EQ(340, v);}
	
TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(975445, 975232);
    ASSERT_EQ(228, v);}
	
// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 4, 3737, 1133);
    ASSERT_EQ("4 3737 1133\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 1337, 407, 9999);
    ASSERT_EQ("1337 407 9999\n", w.str());}
	
// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
	
TEST(CollatzFixture, solve_2) {
    istringstream r("2323 12637\n30000 60000\n975445 975232\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("2323 12637 268\n30000 60000 340\n975445 975232 228\n", w.str());}	

TEST(CollatzFixture, solve_3) {
    istringstream r("12345 67890\n67890 12345\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("12345 67890 340\n67890 12345 340\n", w.str());}	