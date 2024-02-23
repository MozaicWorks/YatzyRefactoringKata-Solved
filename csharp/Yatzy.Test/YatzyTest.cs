using Xunit;
using Yatzy;

namespace Yatzy.Test
{
    public class YatzyTest
    {
        [Fact]
        public void Chance_scores_sum_of_all_dice()
        {
            var expected = 15;
            var actual = new Yatzy(2, 3, 4, 5, 1).ScorePerCategory()["Chance"];
            Assert.Equal(expected, actual);
            Assert.Equal(16, new Yatzy(3, 3, 4, 5, 1).ScorePerCategory()["Chance"]);
        }

        [Fact]
        public void Fact_1s()
        {
            Assert.Equal(1, new Yatzy(1, 2, 3, 4, 5).ScorePerCategory()["Ones"]);
            Assert.Equal(2, new Yatzy(1, 2, 1, 4, 5).ScorePerCategory()["Ones"]);
            Assert.Equal(0, new Yatzy(6, 2, 2, 4, 5).ScorePerCategory()["Ones"]);
            Assert.Equal(4, new Yatzy(1, 2, 1, 1, 1).ScorePerCategory()["Ones"]);
        }

        [Fact]
        public void Fact_2s()
        {
            Assert.Equal(4, new Yatzy(1, 2, 3, 2, 6).ScorePerCategory()["Twos"]);
            Assert.Equal(10, new Yatzy(2, 2, 2, 2, 2).ScorePerCategory()["Twos"]);
        }

        [Fact]
        public void Fact_threes()
        {
            Assert.Equal(6, new Yatzy(1, 2, 3, 2, 3).ScorePerCategory()["Threes"]);
            Assert.Equal(12, new Yatzy(2, 3, 3, 3, 3).ScorePerCategory()["Threes"]);
        }

        [Fact]
        public void fives()
        {
            Assert.Equal(10, new Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Fives"]);
            Assert.Equal(15, new Yatzy(4, 4, 5, 5, 5).ScorePerCategory()["Fives"]);
            Assert.Equal(20, new Yatzy(4, 5, 5, 5, 5).ScorePerCategory()["Fives"]);
        }

        [Fact]
        public void four_of_a_knd()
        {
            Assert.Equal(12, new Yatzy(3, 3, 3, 3, 5).ScorePerCategory()["FourOfAKind"]);
            Assert.Equal(20, new Yatzy(5, 5, 5, 4, 5).ScorePerCategory()["FourOfAKind"]);
            Assert.Equal(12, new Yatzy(3, 3, 3, 3, 3).ScorePerCategory()["FourOfAKind"]);
        }

        [Fact]
        public void fours_Fact()
        {
            Assert.Equal(12, new Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Fours"]);
            Assert.Equal(8, new Yatzy(4, 4, 5, 5, 5).ScorePerCategory()["Fours"]);
            Assert.Equal(4, new Yatzy(4, 5, 5, 5, 5).ScorePerCategory()["Fours"]);
        }

        [Fact]
        public void fullHouse()
        {
            Assert.Equal(18, new Yatzy(6, 2, 2, 2, 6).ScorePerCategory()["FullHouse"]);
            Assert.Equal(0, new Yatzy(2, 3, 4, 5, 6).ScorePerCategory()["FullHouse"]);
        }

        [Fact]
        public void largeStraight()
        {
            Assert.Equal(20, new Yatzy(6, 2, 3, 4, 5).ScorePerCategory()["LargeStraight"]);
            Assert.Equal(20, new Yatzy(2, 3, 4, 5, 6).ScorePerCategory()["LargeStraight"]);
            Assert.Equal(0, new Yatzy(1, 2, 2, 4, 5).ScorePerCategory()["LargeStraight"]);
        }

        [Fact]
        public void one_pair()
        {
            Assert.Equal(6, new Yatzy(3, 4, 3, 5, 6).ScorePerCategory()["Pair"]);
            Assert.Equal(10, new Yatzy(5, 3, 3, 3, 5).ScorePerCategory()["Pair"]);
            Assert.Equal(12, new Yatzy(5, 3, 6, 6, 5).ScorePerCategory()["Pair"]);
        }

        [Fact]
        public void sixes_Fact()
        {
            Assert.Equal(0, new Yatzy(4, 4, 4, 5, 5).ScorePerCategory()["Sixes"]);
            Assert.Equal(6, new Yatzy(4, 4, 6, 5, 5).ScorePerCategory()["Sixes"]);
            Assert.Equal(18, new Yatzy(6, 5, 6, 6, 5).ScorePerCategory()["Sixes"]);
        }

        [Fact]
        public void smallStraight()
        {
            Assert.Equal(15, new Yatzy(1, 2, 3, 4, 5).ScorePerCategory()["SmallStraight"]);
            Assert.Equal(15, new Yatzy(2, 3, 4, 5, 1).ScorePerCategory()["SmallStraight"]);
            Assert.Equal(0, new Yatzy(1, 2, 2, 4, 5).ScorePerCategory()["SmallStraight"]);
        }

        [Fact]
        public void three_of_a_kind()
        {
            Assert.Equal(9, new Yatzy(3, 3, 3, 4, 5).ScorePerCategory()["ThreeOfAKind"]);
            Assert.Equal(15, new Yatzy(5, 3, 5, 4, 5).ScorePerCategory()["ThreeOfAKind"]);
            Assert.Equal(9, new Yatzy(3, 3, 3, 3, 5).ScorePerCategory()["ThreeOfAKind"]);
        }

        [Fact]
        public void two_Pair()
        {
            Assert.Equal(16, new Yatzy(3, 3, 5, 4, 5).ScorePerCategory()["TwoPair"]);
            Assert.Equal(16, new Yatzy(3, 3, 5, 5, 5).ScorePerCategory()["TwoPair"]);
        }

        [Fact]
        public void Yatzy_scores_50()
        {
            var expected = 50;
            var actual = new Yatzy(4, 4, 4, 4, 4).ScorePerCategory()["Yatzy"];
            Assert.Equal(expected, actual);
            Assert.Equal(50, new Yatzy(6, 6, 6, 6, 6).ScorePerCategory()["Yatzy"]);
            Assert.Equal(0, new Yatzy(6, 6, 6, 6, 3).ScorePerCategory()["Yatzy"]);
        }
    }
}