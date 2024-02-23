#ifndef YATZY_INCLUDED
#define YATZY_INCLUDED
#include <string>
#include <vector>
#include <map>

class Yatzy
{

private:
    std::vector<int> dice;

public:
    Yatzy(): dice(5){};
    Yatzy(int d1, int d2, int d3, int d4, int _5):  dice{d1, d2, d3, d4, _5} {};
    std::map<std::string, int> ScorePerCategory();

private:
    int TwoPair(int d1, int d2, int d3, int d4, int d5);
    int FourOfAKind(int _1, int _2, int d3, int d4, int d5);
    int ThreeOfAKind(int d1, int d2, int d3, int d4, int d5);

    int SmallStraight(int d1, int d2, int d3, int d4, int d5);
    int LargeStraight(int d1, int d2, int d3, int d4, int d5);
    int FullHouse(int d1, int d2, int d3, int d4, int d5);
};

#endif