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

//my tests
TEST(CollatzFixture, read_1) {
    istringstream r("100 200\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 100, i);
    ASSERT_EQ( 200, j);}

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

//my tests
TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(10000, 11000);
    ASSERT_EQ(268, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(20938, 42719);
    ASSERT_EQ(324, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(718, 19013);
    ASSERT_EQ(279, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(999000, 998000);
    ASSERT_EQ(396, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(300, 1);
    ASSERT_EQ(128, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(300000, 400000);
    ASSERT_EQ(441, v);}    

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(900, 899);
    ASSERT_EQ(117, v);}  
    
// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

//my tests
TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
