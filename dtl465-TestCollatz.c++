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

// ----
// next_thousand
// ----

TEST(CollatzFixture, thou_1){
    const int v = next_thousand(1100);
    ASSERT_EQ(2000,v);}

TEST(CollatzFixture, thou_2){
    const int v = next_thousand(11000);
    ASSERT_EQ(12000,v);}

TEST(CollatzFixture, thou_3){
    const int v = next_thousand(500);
    ASSERT_EQ(1000,v);}

TEST(CollatzFixture, thou_4){
    const int v = next_thousand(0);
    ASSERT_EQ(1000,v);}
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
    const int v = collatz_eval(100, 400);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(40, 40);
    ASSERT_EQ(9, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(99999, 100000);
    ASSERT_EQ(227, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(100000, 100001);
    ASSERT_EQ(129, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(100500, 101000);
    ASSERT_EQ(266, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(100500, 105000);
    ASSERT_EQ(310, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(100500, 110000);
    ASSERT_EQ(354, v);}

TEST(CollatzFixture, eval_14) {
    const int v = collatz_eval(75268, 73604);
    ASSERT_EQ(325, v);}

TEST(CollatzFixture, eval_15) {
    const int v = collatz_eval(167768, 165790);
    ASSERT_EQ(352, v);}

TEST(CollatzFixture, eval_16) {
    const int v = collatz_eval(150837, 160000);
    ASSERT_EQ(383, v);}

TEST(CollatzFixture, eval_17) {
    const int v = collatz_eval(61799, 55060);
    ASSERT_EQ(335, v);}

TEST(CollatzFixture, eval_18) {
    const int v = collatz_eval(297198, 298655);
    ASSERT_EQ(327, v);}

TEST(CollatzFixture, eval_19) {
    const int v = collatz_eval(5055, 1053);
    ASSERT_EQ(238, v);}


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
