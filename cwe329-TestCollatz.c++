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
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
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
    istringstream r("201 210\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(201, i);
    ASSERT_EQ(210, j);}


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

// Test the same pairs, reversed
TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(200, 100);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(210, 201);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(1000, 900);
    ASSERT_EQ(174, v);}

// Test zero length ranges
TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(10, 10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(100, 100);
    ASSERT_EQ(26, v);}

// Test possible edge cases
TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(2, 2);
    ASSERT_EQ(2, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 201, 210, 89);
    ASSERT_EQ("201 210 89\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("1000 2000\n3000 4000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1000 2000 182\n3000 4000 238\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("1 20\n1 40\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 20 21\n1 40 112\n", w.str());}

// -----
// cycle_length
// -----

TEST(CollatzFixture, cycle_length_1) {
    const int v = cycle_length(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, cycle_length_2) {
    const int v = cycle_length(10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, cycle_length_3) {
    const int v = cycle_length(100);
    ASSERT_EQ(26, v);}

TEST(CollatzFixture, cycle_length_4) {
    const int v = cycle_length(123);
    ASSERT_EQ(47, v);}

TEST(CollatzFixture, cycle_length_5) {
    const int v = cycle_length(1001);
    ASSERT_EQ(143, v);}
