#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "yatzy.hpp"

static int *ints(int a, int b, int c, int d, int e)
{
    int *r = new int[5];
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    r[4] = e;
    return r;
}

TEST_CASE("Ones")
{
    CHECK_EQ(1, Yatzy(1,2,3,4,5).ScorePerCategory()["Ones"]);
    CHECK_EQ(2, Yatzy(1, 2, 1, 4, 5).ScorePerCategory()["Ones"]);
    CHECK_EQ(0, Yatzy(6, 2, 2, 4, 5).ScorePerCategory()["Ones"]);
    CHECK_EQ(4, Yatzy(1, 2, 1, 1, 1).ScorePerCategory()["Ones"]);
}


TEST_CASE("Chance scores sum of all dice")
{
    CHECK_EQ(15, Yatzy(2, 3, 4, 5, 1).ScorePerCategory()["Chance"]);
    CHECK_EQ(16, Yatzy(3, 3, 4, 5, 1).ScorePerCategory()["Chance"]);
}

TEST_CASE("Yatzy scores 50")
{
    CHECK_EQ(50, Yatzy(4, 4, 4, 4, 4).ScorePerCategory()["Yatzy"]);
    CHECK_EQ(50, Yatzy(6, 6, 6, 6, 6).ScorePerCategory()["Yatzy"]);
    CHECK_EQ(0, Yatzy(6, 6, 6, 6, 3).ScorePerCategory()["Yatzy"]);
}

TEST_CASE("twos")
{
    CHECK_EQ(4, Yatzy(1, 2, 3, 2, 6).ScorePerCategory()["Twos"]);
    CHECK_EQ(10, Yatzy(2, 2, 2, 2, 2).ScorePerCategory()["Twos"]);
}

TEST_CASE("threes")
{
    CHECK_EQ(6, Yatzy(1, 2, 3, 2, 3).ScorePerCategory()["Threes"]);
    CHECK_EQ(12, Yatzy(2, 3, 3, 3, 3).ScorePerCategory()["Threes"]);
}

TEST_CASE("fours")
{
    CHECK_EQ(12, Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Fours"]);
    CHECK_EQ(8, Yatzy(4, 4, 5, 5, 5).ScorePerCategory()["Fours"]);
    CHECK_EQ(4, Yatzy(4, 5, 5, 5, 5).ScorePerCategory()["Fours"]);
}

TEST_CASE("fives")
{
    CHECK_EQ(10, Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Fives"]);
    CHECK_EQ(15, Yatzy(4, 4, 5, 5, 5).ScorePerCategory()["Fives"]);
    CHECK_EQ(20, Yatzy(4, 5, 5, 5, 5).ScorePerCategory()["Fives"]);
}

TEST_CASE("sixes")
{
    CHECK_EQ(0, Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Sixes"]);
    CHECK_EQ(6, Yatzy(4, 4, 6, 5, 5).ScorePerCategory()["Sixes"]);
    CHECK_EQ(18, Yatzy(6, 5, 6, 6, 5).ScorePerCategory()["Sixes"]);
}

TEST_CASE("one pair")
{
    CHECK_EQ(6, Yatzy(3, 4, 3, 5, 6).ScorePerCategory()["Pair"]);
    CHECK_EQ(10, Yatzy(5, 3, 3, 3, 5).ScorePerCategory()["Pair"]);
    CHECK_EQ(12, Yatzy(5, 3, 6, 6, 5).ScorePerCategory()["Pair"]);
}

TEST_CASE("two pair")
{
    CHECK_EQ(16, Yatzy(3, 3, 5, 4, 5).ScorePerCategory()["TwoPair"]);
    CHECK_EQ(16, Yatzy(3, 3, 5, 5, 5).ScorePerCategory()["TwoPair"]);
}

TEST_CASE("three of a kind")
{
    CHECK_EQ(9, Yatzy(3, 3, 3, 4, 5).ScorePerCategory()["ThreeOfAKind"]);
    CHECK_EQ(15, Yatzy(5, 3, 5, 4, 5).ScorePerCategory()["ThreeOfAKind"]);
    CHECK_EQ(9, Yatzy(3, 3, 3, 3, 5).ScorePerCategory()["ThreeOfAKind"]);
}

TEST_CASE("four of a kind")
{
    CHECK_EQ(12, Yatzy(3, 3, 3, 3, 5).ScorePerCategory()["FourOfAKind"]);
    CHECK_EQ(20, Yatzy(5, 5, 5, 4, 5).ScorePerCategory()["FourOfAKind"]);
    CHECK_EQ(12, Yatzy(3, 3, 3, 3, 3).ScorePerCategory()["FourOfAKind"]);
}

TEST_CASE("small straight")
{
    CHECK_EQ(15, Yatzy(1, 2, 3, 4, 5).ScorePerCategory()["SmallStraight"]);
    CHECK_EQ(15, Yatzy(2, 3, 4, 5, 1).ScorePerCategory()["SmallStraight"]);
    CHECK_EQ(0, Yatzy(1, 2, 2, 4, 5).ScorePerCategory()["SmallStraight"]);
}

TEST_CASE("large straight")
{
    CHECK_EQ(20, Yatzy(6, 2, 3, 4, 5).ScorePerCategory()["LargeStraight"]);
    CHECK_EQ(20, Yatzy(2, 3, 4, 5, 6).ScorePerCategory()["LargeStraight"]);
    CHECK_EQ(0, Yatzy(1, 2, 2, 4, 5).ScorePerCategory()["LargeStraight"]);
}

TEST_CASE("full house")
{
    CHECK_EQ(18, Yatzy(6, 2, 2, 2, 6).ScorePerCategory()["FullHouse"]);
    CHECK_EQ(0, Yatzy(2, 3, 4, 5, 6).ScorePerCategory()["FullHouse"]);
}
