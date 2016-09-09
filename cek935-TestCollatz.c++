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
#include <map>      // map

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

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(100, 1);
    ASSERT_EQ(119, v);}

std::map<int, int> a;
std::map<int, int> b;

TEST(CollatzFixture, eval_6) {
    const int v = recursiveOptimizedCycle (40, a);
    ASSERT_EQ(9, v);}

TEST(CollatzFixture, eval_7) {
    const int v = recursiveOptimizedCycle (16, a);
    ASSERT_EQ(5, v);}

TEST(CollatzFixture, eval_8) {
    const int v = recursiveOptimizedCycle (4500, a);
    ASSERT_EQ(47, v);}

TEST(CollatzFixture, eval_9) {
    const int v = recursiveOptimizedCycle (100000, a);
    ASSERT_EQ(129, v);}

TEST(CollatzFixture, eval_10) {
    const int v = recursiveOptimizedCycle (13, a);
    ASSERT_EQ(10, v);}

TEST(CollatzFixture, eval_11) {
    const int v = recursiveOptimizedCycle (1, b);
    ASSERT_EQ(1, v);}


TEST(CollatzFixture, eval_12) {
    const int v = unoptimizedMaxCycle(1, 10);
    ASSERT_EQ(20, v);}

TEST(CCollatzFixture, eval_13) {
    const int v = unoptimizedMaxCycle(150, 30);
    ASSERT_EQ(122, v);}

TEST(CollatzFixture, eval_14) {
    const int v = unoptimizedMaxCycle(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_15) {
    const int v = unoptimizedMaxCycle(20, 5);
    ASSERT_EQ(21, v);}

TEST(CollatzFixture, eval_16) {
    const int v = unoptimizedMaxCycle(50, 100000);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_17) {
    const int v = unoptimizedMaxCycle(311, 777);
    ASSERT_EQ(171, v);}


TEST(CollatzFixture, eval_18) {
    const int v = optimizedMaxCycle(349, 9348);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_19) {
    const int v = optimizedMaxCycle(3490, 93485);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_20) {
    const int v = optimizedMaxCycle(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_21) {
    const int v = optimizedMaxCycle(1, 239);
    ASSERT_EQ(128, v);}

TEST(CollatzFixture, eval_22) {
    const int v = optimizedMaxCycle(34, 8);
    ASSERT_EQ(112, v);}

TEST(CollatzFixture, eval_23) {
    const int v = optimizedMaxCycle(100, 1);
    ASSERT_EQ(119, v);}

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
