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
// cycle_length
// ----

TEST(CollatzFixture, cycle_length_1) {
    const int expected[] = { 1, 2, 8, 3, 6, 9, 17, 4, 20, 7 };
    for (int i = 1; i <= 10; ++i)
        EXPECT_EQ(expected[i-1], collatz_cycle_length(i)); }

TEST(CollatzFixture, cycle_length_2) {
    EXPECT_EQ(178, collatz_cycle_length(524287));
    EXPECT_EQ(259, collatz_cycle_length(999999));
    EXPECT_EQ(153, collatz_cycle_length(1000000));}

TEST(CollatzFixture, cycle_length_3) {
    EXPECT_EQ(525, collatz_cycle_length(837799));
    EXPECT_EQ(509, collatz_cycle_length(626331));
    EXPECT_EQ(470, collatz_cycle_length(511935));}

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
    const int v = collatz_eval(1, 1000000);
    ASSERT_EQ(525, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(800000, 900000);
    ASSERT_EQ(525, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 837798);
    ASSERT_EQ(509, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 1, 1000000, 525);
    ASSERT_EQ("1 1000000 525\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("1 1\n1000000 1000000\n837799 837799\n500000 500000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1 1\n1000000 1000000 153\n837799 837799 525\n500000 500000 152\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("1 1000000\n800000 900000\n1 800000\n1 837798\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1000000 525\n800000 900000 525\n1 800000 509\n1 837798 509\n", w.str());}
