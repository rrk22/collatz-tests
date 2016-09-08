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

TEST(CollatzFixture, eval_small_range) {
  const int v = collatz_eval(1, 2);
  ASSERT_EQ(2, v);}

TEST(CollatzFixture, eval_same_number) {
  const int v = collatz_eval(100, 100);
  ASSERT_EQ(26, v);}

TEST(CollatzFixture, eval_large_range) {
  const int v = collatz_eval(1000, 2000);
  ASSERT_EQ(182, v);}

// -----
// print
// -----


TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_two) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  collatz_print(w, 30, 40, 50);
  ASSERT_EQ("1 10 20\n30 40 50\n", w.str());}


// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_same) {
  istringstream r("1 1\n2 2\n4 4\n8 8\n32 32\n64 64\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1 1\n2 2 2\n4 4 3\n8 8 4\n32 32 6\n64 64 7\n", w.str());}

TEST(CollatzFixture, solve_large_range) {
  istringstream r("1 1000\n1000 10000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1000 179\n1000 10000 262\n", w.str());}
