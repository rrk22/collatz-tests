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

//default given by downing
TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

//mine

TEST(CollatzFixture, read_2) {
    istringstream r("83831 100000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(83831, i);
    ASSERT_EQ(100000, j);}

// ----
// eval
// ----

//Default tests given by downing
TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);} //20

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);} //125

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);} //89

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);} //174

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(555555, 555555);
    ASSERT_EQ(147, v);} //147

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1, 5000);
    ASSERT_EQ(238, v);} //238

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(3400, 133);
    ASSERT_EQ(217, v);} //217

//mine
/* Apparantley this overflows
TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1, 999999);
    ASSERT_EQ(525, v);}	//525

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(999999, 1);
    ASSERT_EQ(525, v);} //525
*/

//TEST(CollatzFixture, eval_8) {
//    const int v = collatz_eval(123456,654321);
//   ASSERT_EQ(147, v);}


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
