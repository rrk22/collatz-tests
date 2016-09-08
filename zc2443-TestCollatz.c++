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
#include <map>      // memoization

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

void init_int_array(int size, int val, int start[]) {
    for(int i = 0; i < size; i++) {
        start[i] = val;
    }
}


// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("100 200\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(100, i);
    ASSERT_EQ(200, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("234243 64564\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(234243, i);
    ASSERT_EQ(64564, j);}

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
const int v = collatz_eval(0, 0);
ASSERT_EQ(0, v);}

TEST(CollatzFixture, eval_6) {
const int v = collatz_eval(-1, 1000);
ASSERT_EQ(0, v);}

TEST(CollatzFixture, eval_7) {
const int v = collatz_eval(10, -1);
ASSERT_EQ(0, v);}

// -----------------
// eval naive helper
// -----------------
// first do base cases

TEST(CollatzFixture, eval_naive_0) {
const int v = collatz_helper_naive(0);
ASSERT_EQ(0, v);}

TEST(CollatzFixture, eval_naive_1) {
const int v = collatz_helper_naive(1);
ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_naive_2) {
const int v = collatz_helper_naive(2);
ASSERT_EQ(2, v);}

// now an incorrect input
TEST(CollatzFixture, eval_naive_3) {
const int v = collatz_helper_naive(-843594);
ASSERT_EQ(-1, v);}

// now more complex numbers
TEST(CollatzFixture, eval_naive_4) {
const int v = collatz_helper_naive(2);
ASSERT_EQ(2, v);}

TEST(CollatzFixture, eval_naive_5) {
const int v = collatz_helper_naive(50);
ASSERT_EQ(25, v);}

TEST(CollatzFixture, eval_naive_6) {
const int v = collatz_helper_naive(700);
ASSERT_EQ(83, v);}

TEST(CollatzFixture, eval_naive_7) {
const int v = collatz_helper_naive(999999);
ASSERT_EQ(259, v);}


// -----------------
// eval memoize helper
// -----------------
// first do base cases

TEST(CollatzFixture, eval_memoization_0) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(0, vals);
ASSERT_EQ(0, v);}

TEST(CollatzFixture, eval_memoization_1) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(1, vals);
ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_memoization_2) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(2, vals);
ASSERT_EQ(2, v);}

// now an incorrect input
TEST(CollatzFixture, eval_memoization_3) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(-843594, vals);
ASSERT_EQ(-1, v);}

TEST(CollatzFixture, eval_memoization_4) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(4, vals);
ASSERT_EQ(3, v);}

TEST(CollatzFixture, eval_memoization_5) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(50, vals);
ASSERT_EQ(25, v);}

TEST(CollatzFixture, eval_memoization_6) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(999999, vals);
ASSERT_EQ(259, v);}

TEST(CollatzFixture, eval_memoization_7) {
int *vals = new int[1000000];
const int v = collatz_helper_memoization(700, vals);
ASSERT_EQ(83, v);}

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

TEST(CollatzFixture, solve_0) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_1) {
istringstream r("-1 -4\n100 200\n-23 210\n900 -435\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("-1 -4 0\n100 200 125\n-23 210 0\n900 -435 0\n", w.str());}

TEST(CollatzFixture, solve_2) {
istringstream r("700 700\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("700 700 83\n", w.str());}
