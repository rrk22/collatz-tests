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
    istringstream r("222222222 222222222\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 222222222, i);
    ASSERT_EQ(222222222, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("-1 -2\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( -1, i);
    ASSERT_EQ(-2, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("0 0\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 0, i);
    ASSERT_EQ(0, j);}

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

TEST(CollatzFixture, eval_reversed_range) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture,eval_small_range) {
    const int v = collatz_eval(9,9);
    ASSERT_EQ(20, v);}


// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_length_1) {
    const int v = cycle_length(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, cycle_length_2) {
    const int v = cycle_length(20);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, cycle_length_3) {
    const int v = cycle_length(50005);
    ASSERT_EQ(128, v);}

TEST(CollatzFixture, cycle_length_4) {
    const int v = cycle_length(999999);
    ASSERT_EQ(259, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 0, -100, -200);
    ASSERT_EQ("0 -100 -200\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 333333333, 333333333, 333333333);
    ASSERT_EQ("333333333 333333333 333333333\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_backwards_1) {
    istringstream r("10 1\n200 100\n210 201\n1000 900\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());}

TEST(CollatzFixture, solve_zero_range_1) {
    istringstream r("13 13\n53 53\n2003 2003\n999999 999999\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("13 13 10\n53 53 12\n2003 2003 144\n999999 999999 259\n", w.str());}
