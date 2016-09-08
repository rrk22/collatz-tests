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
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("100000 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(100000, i);
  ASSERT_EQ(1, j);
}

// ----
// length
// ----

TEST(CollatzFixture, length_1) {
  const int l = cycle_length(1);
  ASSERT_EQ(1, l);
}

TEST(CollatzFixture, length_2) {
  const int l = cycle_length(999999);
  ASSERT_EQ(259, l);
}

TEST(CollatzFixture, length_3) {
  const int l = cycle_length(123456);
  ASSERT_EQ(62, l);
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

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(1, 100000);
  ASSERT_EQ(351, v);
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
  collatz_print(w, 92, 12, 116);
  ASSERT_EQ("92 12 116\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 12345, 54321, 340);
  ASSERT_EQ("12345 54321 340\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 1882, 1882, 131);
  ASSERT_EQ("1882 1882 131\n", w.str());
}

TEST(CollatzFixture, print_5) {
  ostringstream w;
  collatz_print(w, 999168, 999999, 396);
  ASSERT_EQ("999168 999999 396\n", w.str());
}

TEST(CollatzFixture, print_6) {
  ostringstream w;
  collatz_print(w, 516416, 516890, 289);
  ASSERT_EQ("516416 516890 289\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("1 10000\n10001 20000\n20001 40000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10000 262\n10001 20000 279\n20001 40000 324\n", w.str());
}
