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
    istringstream r("5 50\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 5, i);
    ASSERT_EQ(50, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("2 200\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 2, i);
    ASSERT_EQ(200, j);}

// ----
// max cycle length
// ----

TEST(CollatzFixture, max_1) {
    const int v = max_cycle_length(2);
    ASSERT_EQ(2, v);}

TEST(CollatzFixture, max_2) {
    const int v = max_cycle_length(3);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, max_3) {
    const int v = max_cycle_length(4);
    ASSERT_EQ(3, v);}

TEST(CollatzFixture, unopt_max_1) {
    const int v = eval_helper(2);
    ASSERT_EQ(2, v);}

TEST(CollatzFixture, unopt_max_2) {
    const int v = eval_helper(3);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, unopt_max_3) {
    const int v = eval_helper(4);
    ASSERT_EQ(3, v);}

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
    const int v = collatz_eval(6, 18);
    ASSERT_EQ(21, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(25, 126);
    ASSERT_EQ(119, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(50, 80);
    ASSERT_EQ(116, v);}

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

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("20 30\n200 300\n301 401\n605293 606510\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("20 30 112\n200 300 128\n301 401 144\n605293 606510 341\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("1 99\n57 200\n203 300\n450 470\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 99 119\n57 200 125\n203 300 128\n450 470 129\n", w.str());}
