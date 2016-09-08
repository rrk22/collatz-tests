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
    istringstream r("2340 578\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 2340, i);
    ASSERT_EQ(578, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("195683 201479\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(195683, i);
    ASSERT_EQ(201479, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("763983 765178\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 763983, i);
    ASSERT_EQ(765178, j);}

// ------
// switch
// ------

TEST(CollatzFixture, switch_1) {
    int i = 100;
    int j = 10;
    const bool b = collatz_switch(i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10, i);
    ASSERT_EQ(100, j);
}

TEST(CollatzFixture, switch_2) {
    int i = 100;
    int j = 10;
    const bool b = collatz_switch(i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10, i);
    ASSERT_EQ(100, j);
}

TEST(CollatzFixture, switch_3) {
    int i = 100;
    int j = 10;
    const bool b = collatz_switch(i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10, i);
    ASSERT_EQ(100, j);
}

TEST(CollatzFixture, switch_4) {
    int i = 100;
    int j = 10;
    const bool b = collatz_switch(i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(10, i);
    ASSERT_EQ(100, j);
}

// ----
// calc
// ----

TEST(CollatzFixture, calc_1) {
    int c;
    int i = 10;
    c = collatz_calc(i);
    ASSERT_EQ(7, c);
}

TEST(CollatzFixture, calc_2) {
    int c;
    int i = 10;
    c = collatz_calc(i);
    ASSERT_EQ(7, c);
}

TEST(CollatzFixture, calc_3) {
    int c;
    int i = 10;
    c = collatz_calc(i);
    ASSERT_EQ(7, c);
}

TEST(CollatzFixture, calc_4) {
    int c;
    int i = 10;
    c = collatz_calc(i);
    ASSERT_EQ(7, c);
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

TEST(CollatzFixture,eval_5) {
    const int v = collatz_eval(11, 20);
    ASSERT_EQ(21, v);}

TEST(CollatzFixture,eval_6) {
    const int v = collatz_eval(23194, 14895);
    ASSERT_EQ(279, v);}

TEST(CollatzFixture,eval_7) {
    const int v = collatz_eval(345983, 357234);
    ASSERT_EQ(379, v);}

TEST(CollatzFixture,eval_8) {
    const int v = collatz_eval(999258, 999999);
    ASSERT_EQ(396, v);}

TEST(CollatzFixture,eval_9) {
    const int v = collatz_eval(670349, 680273);
    ASSERT_EQ(385, v);}
// -----


// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 58, 92, 116);
    ASSERT_EQ("58 92 116\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 28647, 36564, 324);
    ASSERT_EQ("28647 36564 324\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 240967, 241735, 275);
    ASSERT_EQ("240967 241735 275\n", w.str());}


// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("23903 56033\n78402 90234\n809345 810734\n23479 29349\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("23903 56033 340\n78402 90234 338\n809345 810734 406\n23479 29349 308\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("5633 6856\n999200 999500\n564723 561350\n904 230\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("5633 6856 262\n999200 999500 396\n564723 561350 359\n904 230 179\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("473 954\n43 98\n987 367\n1713 985\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("473 954 179\n43 98 119\n987 367 179\n1713 985 182\n", w.str());}