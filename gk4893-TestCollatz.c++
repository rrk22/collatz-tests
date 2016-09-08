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

TEST(CollatzFixture, read1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read2) {
    istringstream r("459760 466990\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 459760, i);
    ASSERT_EQ(466990, j);}

TEST(CollatzFixture, read3) {
    istringstream r("561152 565246\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 561152, i);
    ASSERT_EQ(565246, j);}

TEST(CollatzFixture, read4) {
    istringstream r("969215 971773\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 969215, i);
    ASSERT_EQ(971773, j);}

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
    const int v = collatz_eval(459760, 466990);
    ASSERT_EQ(444, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(561152, 565246);
    ASSERT_EQ(421, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(669922, 680299);
    ASSERT_EQ(385, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(969215, 971773);
    ASSERT_EQ(458, v);}
// -----
// print
// -----

TEST(CollatzFixture, print1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print2) {
    ostringstream w;
    collatz_print(w, 459760, 466990, 444);
    ASSERT_EQ("459760 466990 444\n", w.str());}

TEST(CollatzFixture, print3) {
    ostringstream w;
    collatz_print(w, 561152, 565246, 421);
    ASSERT_EQ("561152 565246 421\n", w.str());}

TEST(CollatzFixture, print4) {
    ostringstream w;
    collatz_print(w, 969215, 971773, 458);
    ASSERT_EQ("969215 971773 458\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve2) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n459760 466990\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n459760 466990 444\n", w.str());}

TEST(CollatzFixture, solve3) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n561152 565246\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n561152 565246 421\n", w.str());}

TEST(CollatzFixture, solve4) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n669922 680299\n969215 971773\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n669922 680299 385\n969215 971773 458\n", w.str());}
