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
    ASSERT_EQ(1, i);
    ASSERT_EQ(10, j);}

    TEST(CollatzFixture, read_2) {
    istringstream r("5 50\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(5, i);
    ASSERT_EQ(50, j);}

    TEST(CollatzFixture, read_3) {
    istringstream r("10000 30000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10000, i);
    ASSERT_EQ(30000, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(963920, 966769);
    ASSERT_EQ(365, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(716572, 716593);
    ASSERT_EQ(305, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(163649, 167286);
    ASSERT_EQ(352, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(709499, 713119);
    ASSERT_EQ(411, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 963920, 966769, 365);
    ASSERT_EQ("963920 966769 365\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 716572, 716593, 305);
    ASSERT_EQ("716572 716593 305\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 163649, 167286, 352);
    ASSERT_EQ("163649 167286 352\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("963920 966769\n716572 716593\n163649 167286\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("963920 966769 365\n716572 716593 305\n163649 167286 352\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("33995 95360\n360484 361974\n728139 728565\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("33995 95360 351\n360484 361974 366\n728139 728565 287\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("483554 483570\n752812 752972\n317071 318562\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("483554 483570 214\n752812 752972 287\n317071 318562 309\n", w.str());}
