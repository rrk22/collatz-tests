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
#include <utility>

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
    ASSERT_EQ(10, j);
}



TEST(CollatzFixture, read_2) {
  istringstream r("1338 1690\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1338, i);
  ASSERT_EQ(1690, j);
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

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1338, 1690);
    ASSERT_EQ(180, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(394, 85);
    ASSERT_EQ(144, v);}


// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}


TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1338, 1690, 180);
    ASSERT_EQ("1338 1690 180\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}


TEST(CollatzFixture, solve_2) {
    istringstream r("1338 1690\n394 85\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1338 1690 180\n394 85 144\n", w.str());}
