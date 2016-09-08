// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <climits>
#include <cstdint>
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

TEST(CollatzFixture, read_1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("-2147483648 2147483647\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(INT_MIN, i);
  ASSERT_EQ(INT_MAX, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("1 1000000\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(1000000, j);
}

// --------------------
// collatz_cycle_length
// --------------------

TEST(CollatzFixture, collatz_cycle_length_1) {
  ASSERT_EQ(6, collatz_cycle_length(5));
}

TEST(CollatzFixture, collatz_cycle_length_2) {
  ASSERT_EQ(25, collatz_cycle_length(50));
}

TEST(CollatzFixture, collatz_cycle_length_3) {
  ASSERT_EQ(29, collatz_cycle_length(5000));
}

TEST(CollatzFixture, collatz_cycle_length_4) {
  ASSERT_EQ(152, collatz_cycle_length(500000));
}

// ------------------------
// collatz_max_cycle_length
// ------------------------

TEST(CollatzFixture, collatz_max_cycle_length_1) {
  ASSERT_EQ(20, collatz_max_cycle_length(1, 10));
}

TEST(CollatzFixture, collatz_max_cycle_length_2) {
  ASSERT_EQ(125, collatz_max_cycle_length(100, 200));
}

TEST(CollatzFixture, collatz_max_cycle_length_3) {
  ASSERT_EQ(89, collatz_max_cycle_length(201, 210));
}

TEST(CollatzFixture, collatz_max_cycle_length_4) {
  ASSERT_EQ(174, collatz_max_cycle_length(900, 1000));
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(201, 210);
  ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 100, 200, 125);
  ASSERT_EQ("100 200 125\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 201, 210, 89);
  ASSERT_EQ("201 210 89\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}
