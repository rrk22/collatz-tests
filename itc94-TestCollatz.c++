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
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// ----
// range_adjust
// ----

TEST(CollatzFixture, range_1) {
  int i = 1;
  int j = 10;
  range_adjust(i, j);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, range_2) {
  int i = 10;
  int j = 1;
  range_adjust(i, j);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, range_3) {
  int i = 10;
  int j = 10;
  range_adjust(i, j);
  ASSERT_EQ(10, i);
  ASSERT_EQ(10, j);
}

// ----
// cycle_length
// ----

TEST(CollatzFixture, cycle_length_1) { ASSERT_EQ(1, cycle_length(1)); }

TEST(CollatzFixture, cycle_length_2) { ASSERT_EQ(7, cycle_length(10)); }

TEST(CollatzFixture, cycle_length_3) { ASSERT_EQ(40, cycle_length(210)); }

TEST(CollatzFixture, cycle_length_4) { ASSERT_EQ(160, cycle_length(99978)); }

TEST(CollatzFixture, cycle_length_5) { ASSERT_EQ(30, cycle_length(10000)); }

TEST(CollatzFixture, cycle_length_6) { ASSERT_EQ(259, cycle_length(999999)); }

TEST(CollatzFixture, cycle_length_lazy_1) {
  ASSERT_EQ(1, cycle_length_lazy(1));
}

TEST(CollatzFixture, cycle_length_lazy_2) {
  ASSERT_EQ(7, cycle_length_lazy(10));
}

TEST(CollatzFixture, cycle_length_lazy_3) {
  ASSERT_EQ(40, cycle_length_lazy(210));
}

TEST(CollatzFixture, cycle_length_lazy_4) {
  ASSERT_EQ(160, cycle_length_lazy(99978));
}

TEST(CollatzFixture, cycle_length_lazy_5) {
  ASSERT_EQ(30, cycle_length_lazy(10000));
}

TEST(CollatzFixture, cycle_length_lazy_6) {
  ASSERT_EQ(259, cycle_length_lazy(999999));
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

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
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
