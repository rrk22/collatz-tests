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
// cycle length
// ----

TEST(CollatzFixture, cycle_length_1) {
  const int v = cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_2) {
  const int v = cycle_length(1000000);
  ASSERT_EQ(153, v);
}

TEST(CollatzFixture, cycle_length_3) {
  const int v = cycle_length(54321);
  ASSERT_EQ(40, v);
}

TEST(CollatzFixture, cycle_length_4) {
  const int v = cycle_length(3000000);
  ASSERT_EQ(113, v);
}

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
  const int v = collatz_eval(11, 110);
  ASSERT_EQ(119, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(111, 1110);
  ASSERT_EQ(179, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(10001, 20000);
  ASSERT_EQ(279, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(10001, 50000);
  ASSERT_EQ(324, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(10001, 40000);
  ASSERT_EQ(324, v);
}

TEST(CollatzFixture, eval_10) {
  const int v = collatz_eval(10001, 12300);
  ASSERT_EQ(268, v);
}

TEST(CollatzFixture, eval_11) {
  const int v = collatz_eval(12301, 20000);
  ASSERT_EQ(279, v);
}

// Randomly generated tests shown to be problematic

TEST(CollatzFixture, eval_12) {
  const int v = collatz_eval(788836, 791387);
  ASSERT_EQ(406, v);
}

TEST(CollatzFixture, eval_13) {
  const int v = collatz_eval(809210, 810518);
  ASSERT_EQ(406, v);
}

TEST(CollatzFixture, eval_14) {
  const int v = collatz_eval(947523, 950576);
  ASSERT_EQ(383, v);
}

TEST(CollatzFixture, eval_15) {
  const int v = collatz_eval(930036, 929896);
  ASSERT_EQ(264, v);
}

TEST(CollatzFixture, eval_16) {
  const int v = collatz_eval(810273, 809602);
  ASSERT_EQ(344, v);
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
