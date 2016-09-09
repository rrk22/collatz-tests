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
  istringstream r("555555 999999\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(555555, i);
  ASSERT_EQ(999999, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("31 31\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(31, i);
  ASSERT_EQ(31, j);
}

// ----
// eval/loop_optimized/loop_unoptimized
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

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(30, 30);
  ASSERT_EQ(19, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(700, 100);
  ASSERT_EQ(145, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(500, 12);
  ASSERT_EQ(144, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(100, 101);
  ASSERT_EQ(26, v);
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
  collatz_print(w, 142500, 777, 989601);
  ASSERT_EQ("142500 777 989601\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 956, 1, 999999);
  ASSERT_EQ("956 1 999999\n", w.str());
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
  istringstream r("88 66\n555555 999999\n50 24\n12 24\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("88 66 116\n555555 999999 525\n50 24 112\n12 24 21\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("55 55\n55 100\n2 55\n1 999999\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("55 55 113\n55 100 119\n2 55 113\n1 999999 525\n", w.str());
}
