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
    istringstream r("76 67\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 76, i);
    ASSERT_EQ(67, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("200 201\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 200, i);
    ASSERT_EQ(201, j);}

// ---------
// algorithm
// ---------

TEST(CollatzFixture, algorithm_1) {
    int current = 1;
    int n = 1;
    collatz_algorithm(n, current);
    ASSERT_EQ(1, current);
}

TEST(CollatzFixture, algorithm_2) {
    int current = 1;
    int n = 5;
    collatz_algorithm(n, current);
    ASSERT_EQ(6, current);
}

TEST(CollatzFixture, algorithm_3) {
    int current = 1;
    int n = 10;
    collatz_algorithm(n, current);
    ASSERT_EQ(7, current);
}

// -------------
// compute_range
// -------------

TEST(CollatzFixture, compute_range_1) {
    int i = 1;
    int j = 10;
    int maxCycleLength = 1;
    collatz_compute_range(i, j, maxCycleLength);
    ASSERT_EQ(20, maxCycleLength);
}

TEST(CollatzFixture, compute_range_2) {
    int i = 89;
    int j = 89;
    int maxCycleLength = 1;
    collatz_compute_range(i, j, maxCycleLength);
    ASSERT_EQ(31, maxCycleLength);
}

TEST(CollatzFixture, compute_range_3) {
    int i = 100;
    int j = 1235;
    int maxCycleLength = 1;
    collatz_compute_range(i, j, maxCycleLength);
    ASSERT_EQ(182, maxCycleLength);
}

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
    const int v = collatz_eval(89, 89);
    ASSERT_EQ(31, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(89, 90);
    ASSERT_EQ(31, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(90, 89);
    ASSERT_EQ(31, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(100, 1235);
    ASSERT_EQ(182, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 376, 212, 144);
    ASSERT_EQ("376 212 144\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("200 1000\n1 1\n376 212\n453 486\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("200 1000 179\n1 1 1\n376 212 144\n453 486 129\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("13 14\n12 355\n15 16\n120 123\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("13 14 18\n12 355 144\n15 16 18\n120 123 96\n", w.str());}