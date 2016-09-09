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

// test helper method that find individual cycle lengths
TEST(CollatzFixture, eval_5) {
    const int v = computeCycleLength(10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, eval_6) {
    const int v = computeCycleLength(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_7) {
    const int v = computeCycleLength(1000);
    ASSERT_EQ(112, v);}

// if optimization is enabled, test cache (make sure its storing correct values)
TEST(CollatzFixture, eval_8) {
    collatz_eval(1, 2);
    ASSERT_EQ(getDataCycleLengthCache(1), 1);
    ASSERT_EQ(getDataCycleLengthCache(2), 2);
    ASSERT_EQ(getDataCycleLengthCache(15), 18);
    ASSERT_EQ(getDataCycleLengthCache(3000001), 113);
}
TEST(CollatzFixture, eval_9) {
    collatz_eval(10, 15);
    ASSERT_EQ(getDataCycleLengthCache(10), 7);
    ASSERT_EQ(getDataCycleLengthCache(5), 6);
    ASSERT_EQ(getDataCycleLengthCache(15), 18);
    ASSERT_EQ(getDataCycleLengthCache(16), 5);
    ASSERT_EQ(getDataCycleLengthCache(46), 17);
    ASSERT_EQ(getDataCycleLengthCache(1), 1);
}
TEST(CollatzFixture, eval_10) {
    collatz_eval(999, 1000);
    ASSERT_EQ(getDataCycleLengthCache(999), 50);
    ASSERT_EQ(getDataCycleLengthCache(16), 5);
    ASSERT_EQ(getDataCycleLengthCache(1000), 112);

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
