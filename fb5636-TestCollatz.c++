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
#include <utility>  // pair

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

// ------------
// cycle_length
// ------------
    
TEST(CollatzFixture, length_1) {
    const int c = cycle_length(1);
    ASSERT_EQ(1, c);}

TEST(CollatzFixture, length_2) {
    const int c = cycle_length(30);
    ASSERT_EQ(19, c);}

TEST(CollatzFixture, length_cache_1) {
    const int c = cycle_length(30);
    ASSERT_EQ(19, c);}

TEST(CollatzFixture, length_cache_2) {
    const int c = cycle_length(1);
    ASSERT_EQ(1, c);}

TEST(CollatzFixture, length_cache_3) {
    const int c = cycle_length(60);
    ASSERT_EQ(20, c);}


// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(101, 210);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(799, 3000);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_reverse_1) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_reverse_2) {
    const int v = collatz_eval(210, 101);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, cahce_1) {
    const int v = collatz_eval(201, 3500);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, cahce_2) {
    const int v = collatz_eval(399, 4500);
    ASSERT_EQ(238, v);
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
