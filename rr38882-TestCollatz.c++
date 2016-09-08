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
  istringstream r("10 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(10, i);
  ASSERT_EQ(1, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_FALSE(b);
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
  const int v = collatz_eval(1000, 900);
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
  collatz_print(w, 1, 10, 20);
  ASSERT_NE("20 10 1\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 16, 0, 2);
  ASSERT_EQ("16 0 2\n", w.str());
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
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_NE("1 10 22\n100 200 122\n201 210 82\n900 1000 172\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("38391 44816\n104924 17309\n35804 69043\n82886 36686\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ(
      "38391 44816 306\n104924 17309 351\n35804 69043 340\n82886 36686 351\n",
      w.str());
}
