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
    istringstream r("1 -10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(-10, j);}
TEST(CollatzFixture, read_3) {
    istringstream r("-1 -10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( -1, i);
    ASSERT_EQ(-10, j);
}
TEST(CollatzFixture, read_4) {
    istringstream r("100000 100000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 100000, i);
    ASSERT_EQ(100000, j);
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
    const int v = collatz_eval(100000, 100000);
    ASSERT_EQ(129, v);}

// // -----
// // print
// // -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}
TEST(CollatzFixture, print_2_negative) {
    ostringstream w;
    collatz_print(w, -1, -10, -20);
    ASSERT_EQ("-1 -10 -20\n", w.str());}
TEST(CollatzFixture, print_3_long) {
    ostringstream w;
    collatz_print(w, -1, -10L, -20L);
    ASSERT_EQ("-1 -10 -20\n", w.str());}

// // -----
// // solve
// // -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
TEST(CollatzFixture, solve_2) {
    istringstream r("99 1\n1 99\n100000 4\n500000 214124\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("99 1 119\n1 99 119\n100000 4 351\n500000 214124 449\n", w.str());}
TEST(CollatzFixture, solve_3_same) {
    istringstream r("50 50");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("50 50 25\n", w.str());}
TEST(CollatzFixture, solve_4_no_endl) {
    istringstream r("");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("", w.str());}
TEST(CollatzFixture, solve_5_no_endl_w_values) {
    istringstream r("50 50");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("50 50 25\n", w.str());}
TEST(CollatzFixture, solve_6_ones) {
    istringstream r("1 1");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1 1\n", w.str());}

// // -----
// // length
// // -----
TEST(CollatzFixture, length_1) {
	ASSERT_EQ(1, collatz_length(1));
}
TEST(CollatzFixture, length_2) {
	ASSERT_EQ(26, collatz_length(100));
}
TEST(CollatzFixture, length_3) {
	ASSERT_EQ(112, collatz_length(1000));
}
TEST(CollatzFixture, length_4) {
	ASSERT_EQ(30, collatz_length(10000));
}
TEST(CollatzFixture, length_5) {
	ASSERT_EQ(129, collatz_length(100000));
}
TEST(CollatzFixture, length_6) {
	ASSERT_EQ(153, collatz_length(1000000));
}


