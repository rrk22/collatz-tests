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

TEST(CollatzFixture, read_none) {
    istringstream r("");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_FALSE(b);}
    
TEST(CollatzFixture, read_one) {
    istringstream r("1, 0\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_EQ(1, i);
    ASSERT_EQ(0, j);
    ASSERT_TRUE(b);}

TEST(CollatzFixture, read_two) {
    istringstream r("1 1000\n9990 78\n");
    int i;
    int j;
    bool b = collatz_read(r, i, j);
    ASSERT_EQ(1, i);
    ASSERT_EQ(1000, j);
    ASSERT_TRUE(b);
    
    b = collatz_read(r, i, j);
    ASSERT_EQ(9990, i);
    ASSERT_EQ(78, j);
    ASSERT_TRUE(b);}


// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(62742, 67164);
    ASSERT_EQ(330, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(7075, 72332);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(73189, 85972);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(3077, 1669);
    ASSERT_EQ(217, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_one) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_two) {
    ostringstream w;
    collatz_print(w, 47, 100, 119);
    ASSERT_EQ("47 100 119\n", w.str());}

TEST(CollatzFixture, print_three) {
    ostringstream w;
    collatz_print(w, 10938, 2, 262);
    ASSERT_EQ("10938 2 262\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_same) {
    istringstream r("100000 100000\n200000 200000\n50000 50000\n74000 74000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("100000 100000 129\n200000 200000 130\n50000 50000 128\n74000 74000 38\n", w.str());}

TEST(CollatzFixture, solve_large) {
    istringstream r("1 10000\n1 50000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10000 262\n1 50000 324\n", w.str());}
