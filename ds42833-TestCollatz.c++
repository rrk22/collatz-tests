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

//My tests
TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(999999, 999999);
  ASSERT_EQ(259, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(40861, 18194);
  ASSERT_EQ(324, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(1075, 24479);
  ASSERT_EQ(282, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(77446, 14622);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(33882, 49463);
  ASSERT_EQ(324, v);
}

TEST(CollatzFixture, eval_10) {
  const int v = collatz_eval(91226, 30552);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_12) {
  const int v = collatz_eval(56770, 30089);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_13) {
  const int v = collatz_eval(5084, 2762);
  ASSERT_EQ(238, v);
}

TEST(CollatzFixture, eval_14) {
  const int v = collatz_eval(91974, 91248);
  ASSERT_EQ(333, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve2) {
    istringstream r("1336 8656\n1995 6069\n2582 9455\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1336 8656 262\n1995 6069 238\n2582 9455 262\n", w.str());}

TEST(CollatzFixture, solve3) {
    istringstream r("2141 5932\n2699 9256\n1551 5045\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("2141 5932 238\n2699 9256 262\n1551 5045 238\n", w.str());}
