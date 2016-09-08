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

TEST(CollatzFixture, read_1) {
    istringstream r("100 200\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(100, i);
    ASSERT_EQ(200, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("201 210\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(201, i);
    ASSERT_EQ(210, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("900 1000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(900, i);
    ASSERT_EQ(1000, j);}

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
    const int v = collatz_eval(533388, 535286);
    ASSERT_EQ(346, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(592920, 596831);
    ASSERT_EQ(372, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(739026, 747039);
    ASSERT_EQ(424, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 73557, 95590, 351);
    ASSERT_EQ("73557 95590 351\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 835047, 835234, 207);
    ASSERT_EQ("835047 835234 207\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_1) {
    istringstream r("373069 374571\n503303 503984\n242630 243928\n871844 872058\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("373069 374571 348\n503303 503984 320\n242630 243928 337\n871844 872058 432\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("593406 594407\n645377 645558\n15794 80076\n45195 63807\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("593406 594407 328\n645377 645558 279\n15794 80076 351\n45195 63807 340\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("727271 727368\n918831 919178\n989084 990473\n402707 402918\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("727271 727368 318\n918831 919178 339\n989084 990473 352\n402707 402918 268\n", w.str());}
